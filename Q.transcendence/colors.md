# Colors in bash

```bash
# ================ BASIC COLORS ================
BLACK       = \033[30m
RED         = \033[31m
GREEN       = \033[32m
YELLOW      = \033[33m
BLUE        = \033[34m
MAGENTA     = \033[35m
CYAN        = \033[36m
WHITE       = \033[37m
ORANGE      = \033[38;5;208m

# ================ RGB COLORS ================
REDD        = \033[0;38;2;255;0;0m
RED1        = \033[0;38;2;210;10;10m
ORNG        = \033[0;38;2;205;105;0m
GOLD        = \033[0;38;2;255;215;0m
YLLW        = \033[0;38;2;255;255;0m
GRNN        = \033[0;38;2;0;128;0m
LIME        = \033[0;38;2;0;255;0m
INDI        = \033[0;38;2;75;0;130m
PURP        = \033[0;38;2;238;130;238m
MAGN        = \033[0;38;2;255;0;255m
PINK        = \033[0;38;2;255;192;203m
BROW        = \033[0;38;2;165;42;42m
IVRY        = \033[0;38;2;255;255;240m
GRY1        = \033[0;38;2;128;128;128m
GRY2        = \033[0;38;2;170;170;170m
SLVR        = \033[0;38;2;192;192;192m
TURQ        = \033[0;38;2;64;224;208m
CORL        = \033[0;38;2;255;127;80m
SALM        = \033[0;38;2;250;128;114m
PLUM        = \033[0;38;2;221;160;221m
TEAL        = \033[0;38;2;0;128;128m
OLIV        = \033[0;38;2;128;128;0m
MINT        = \033[0;38;2;189;252;201m
NAVY        = \033[0;38;2;0;0;128m
PEAC        = \033[0;38;2;175;238;238m
LAVN        = \033[0;38;2;230;230;250m
EMRD        = \033[0;38;2;80;200;120m
RUBY        = \033[0;38;2;224;17;95m

# ================ TEXT STYLES ================
BOLD        = \033[1m
DIM         = \033[2m
ITAL        = \033[3m
UNDERLINE   = \033[4m
BLINK_SLOW  = \033[5m
BLINK_FAST  = \033[6m
REVERSE     = \033[7m
HIDDEN      = \033[8m
STRIKE      = \033[9m

# ================ BACKGROUND COLORS ================
BG_BLACK    = \033[40m
BG_RED      = \033[41m
BG_GREEN    = \033[42m
BG_YELLOW   = \033[43m
BG_BLUE     = \033[44m
BG_MAGENTA  = \033[45m
BG_CYAN     = \033[46m
BG_WHITE    = \033[47m

# ================ SPECIAL ================
RESET       = \033[0m
CLRALL      = \033[2J\033[3J\033[H
CLEAR       = \033c
CLEAR_LINE  = \033[2K

# ================ EMOJIS ================
FALSE_EMOJI = ❌
TRUE_EMOJI  = ✅

# ================ USAGE EXAMPLES ================
# @echo "$(BOLD)$(RED)Error:$(RESET) Something went wrong"
# @echo "$(BOLD)$(GREEN)Success!$(RESET) Operation completed"
# @echo "$(BOLD)$(YELLOW)Warning:$(RESET) This is a warning"
# @echo "$(BOLD)$(BLUE)Info:$(RESET) Processing data..."
# @echo "$(UNDERLINE)Important$(RESET) notice"
# @echo "Loading $(BLINK_SLOW)...$(RESET)"
# @echo "$(BG_RED)$(WHITE)White on red$(RESET)"
# @echo "$(BOLD)$(GOLD)Custom gold color$(RESET)"
# @echo "$(TRUE_EMOJI) Operation successful"
# @echo "$(FALSE_EMOJI) Operation failed"
```
