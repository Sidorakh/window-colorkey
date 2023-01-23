enum WINDOW_TRANSPARENCY_MODE {
	ALPHA=0x00000002,
	COLOR_KEY=0x00000001,
}
/// feather disable GM1041
function window_set_transparency(color,alpha=255,mode=WINDOW_TRANSPARENCY_MODE.COLOR_KEY) {
	//var r = color_get_red(color), g=color_get_green(color), b=color_get_blue(color);
	return window_colorkey_set_transparency(window_handle(),color, alpha, mode);
}

function window_set_always_on_top(on_top) {
	return window_colorkey_set_always_on_top(window_handle(),on_top);
}

function window_get_error() {
	return window_colorkey_get_error();
}

function window_mouse_x() {
	return window_get_raw_mouse_x(window_handle());
}

function window_mouse_y() {
	return window_get_raw_mouse_y(window_handle());
}
/// feather enable GM1041