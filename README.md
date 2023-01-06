# window-colorkey
Window transparency pakckaged in a DLL (Windows only)
C++ source is located in `./transparent-window` as a VS2019 project. 

## Exposed functions:
### `window_set_transparency`
| Parameter | Type | Description |
| -- | -- |--|
| color | Constant.Color | Colour to make transparent |
| alpha | Real | Alpha value to make transparent (unused?) |
| mode | Enum | Transparency mode (enum: `WINDOW_TRANSPARENCY_MODE`) |

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
