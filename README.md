# window-colorkey
Window transparency packaged in a DLL (Windows only)
C++ source is located in `./transparent-window` as a VS2019 project. 

## Exposed functions:
### `window_set_transparency`
| Parameter | Type | Description | Notes |
| -- | -- |--| -- |
| color | Constant.Color | Colour to make transparent | Used by `WINDOW_TRANSPARENCY_MODE.COLOR_KEY` |
| alpha | Real | Sets the alpha value of non-chroma keyed portions of the window | Used by `WINDOW_TRANSPARENCY_MODE.ALPHA` |
| mode | Real | Sets whether the `color` and/or `alpha` arguments are used | Both `WINDOW_TRANSPARENCY_MODE` values can be used to create a bitmask so that the `color` and `alpha` params are used together |

Returns: none


### window_set_always_on_top
| Parameter | Type | Description |
| -- | -- | -- |
| on_top | Boolean | Whether or not to set the window to be on top |

Returns: none

### window_get_error
Parameters: none

Returns: Real


## Notes

Only use colours with equal red and blue values for the colour key. I'd recommend `c_lime` or a shade of grey. If you don't, some weird effects can happen, such as not being able to click through a transparent part of the window or being able to click through an opaque part of the window depending no the colours you use. 

`window_set_always_on_top` may not work at the start of the game, so you may need to wait a few frames before you can successfully use it. 
