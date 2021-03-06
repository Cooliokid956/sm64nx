// white_puff_explode.c.inc

void bhv_white_puff_exploding_loop(void)
{
	f32 sp24;
	if(o->oTimer == 0)
	{
		obj_compute_vel_xz();
		o->oWhitePuffUnkF4 = o->header.gfx.scale[0];

		switch(o->oBehParams2ndByte)
		{
			case 2:
				o->oOpacity	   = 254;
				o->oWhitePuffUnkF8 = -21;
				o->oWhitePuffUnkFC = 0;
				break;
			case 3:
				o->oOpacity	   = 254;
				o->oWhitePuffUnkF8 = -13;
				o->oWhitePuffUnkFC = 1;
				break;
		}
	}
	obj_move_using_vel_and_gravity();
	obj_apply_drag_xz(o->oDragStrength);

	if(o->oVelY > 100.0f)
		o->oVelY = 100.0f;

	if(o->oTimer > 20 * FRAME_RATE_SCALER_INV)
		mark_object_for_deletion(o);

	if(o->oOpacity)
	{
		o->oOpacity += o->oWhitePuffUnkF8 / FRAME_RATE_SCALER_INV;

		if(o->oOpacity < 2)
			mark_object_for_deletion(o);

		if(o->oWhitePuffUnkFC)
			sp24 = o->oWhitePuffUnkF4 * ((254 - o->oOpacity) / 254.0);

		else
			sp24 = o->oWhitePuffUnkF4 * (o->oOpacity / 254.0);

		obj_scale(sp24);
	}
}
