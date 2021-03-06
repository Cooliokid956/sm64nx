
/**
 * Behavior for bhvTTCTreadmill.
 * The first treadmill in processing order is the "master treadmill". It is
 * responsible for playing sounds and calling RNG to control all the other
 * treadmills.
 */

/**
 * Collision models for the different sized treadmills.
 */
static const void* sTTCTreadmillCollisionModels[] = {
    ttc_seg7_collision_070152B4,
    ttc_seg7_collision_070153E0,
};

static s16 sTTCTreadmillSpeeds[] = {
    /* TTC_SPEED_SLOW    */ 50,
    /* TTC_SPEED_FAST    */ 100,
    /* TTC_SPEED_RANDOM  */ 0,
    /* TTC_SPEED_STOPPED */ 0,
};

// TODO: bss

/**
 * The treadmill that plays sounds and controls the others on random setting.
 */
struct Object* sMasterTreadmill;

void bhv_ttc_treadmill_init(void)
{
	o->collisionData = segmented_to_virtual(sTTCTreadmillCollisionModels[o->oBehParams2ndByte & 0x1]);

	o->oTTCTreadmillBigSurface   = (s16*)segmented_to_virtual(ttc_movtex_tris_big_surface_treadmill);
	o->oTTCTreadmillSmallSurface = (s16*)segmented_to_virtual(ttc_movtex_tris_small_surface_treadmill);

	*o->oTTCTreadmillBigSurface = *o->oTTCTreadmillSmallSurface = sTTCTreadmillSpeeds[gTTCSpeedSetting];

	sMasterTreadmill = NULL;
}

/**
 * Update function for bhvTTCTreadmill. It calls obj_compute_vel_xz afterward.
 */
void bhv_ttc_treadmill_update(void)
{
	if(sMasterTreadmill == o || sMasterTreadmill == NULL)
	{
		sMasterTreadmill = o;

		PlaySound(SOUND_ENV_ELEVATOR2);

		if(gTTCSpeedSetting == TTC_SPEED_RANDOM)
		{
			// Stay still for 5 frames, then accelerate toward the target speed
			// until it's time to switch
			if(o->oTimer > o->oTTCTreadmillTimeUntilSwitch * FRAME_RATE_SCALER_INV)
			{
				// Then stop and select new target speed and time until switch
				if(approach_f32_ptr(&o->oTTCTreadmillSpeed, 0.0f, 10.0f * FRAME_RATE_SCALER))
				{
					o->oTTCTreadmillTimeUntilSwitch = random_mod_offset(10, 20, 7);
					o->oTTCTreadmillTargetSpeed	= RandomSign() * 50.0f;
					o->oTimer			= 0;
				}
			}
			else if(o->oTimer > 5 * FRAME_RATE_SCALER_INV)
			{
				approach_f32_ptr(&o->oTTCTreadmillSpeed, o->oTTCTreadmillTargetSpeed, 10.0f * FRAME_RATE_SCALER);
			}

			*o->oTTCTreadmillBigSurface = *o->oTTCTreadmillSmallSurface = o->oTTCTreadmillSpeed;
		}
	}

	o->oForwardVel = 0.084f * *o->oTTCTreadmillBigSurface;
}
