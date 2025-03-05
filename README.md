# uNTils
Utilities for old Windows NT.

## arcvar
Utility for modifying ARC NVRAM variables from the booted OS.

Build with [Open Watcom 1.7 AXP cross-compiler](https://www.ext.zx.net.nz/software/notes/watcom-axp/).

Show boot configuration:
```
arcvar
arcvar boot
```

Get variable:
```
arcvar get VARIABLENAME
```

Set variable:
```
argvar set VARIABLENAME "Variable Value"
```
