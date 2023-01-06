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
