# Exam02 + Level 02 Solutions Summary

This document summarizes what was scanned and implemented in:
- /Users/khant.h/Documents/42 C Piscine/42bangkok-c-piscine-july2026/Exams Practice/Exam02
- /Users/khant.h/Documents/42 C Piscine/42bangkok-c-piscine-july2026/Exams Practice/C-Piscine-exam/Level 02

All discovered exercise source files were implemented, and missing expected files were added.

## 1) What was implemented

### Exam02
- 0-aff_a/aff_a.c
- 0-aff_z/aff_z.c
- 1-ft_strlen/ft_strlen.c
- 1-ft_swap/ft_swap.c
- 1-rev_print/rev_print.c
- 2-first_word/first_word.c
- 2-ft_strrev/ft_strrev.c
- 2-rot_13/rot_13.c
- 2-rotone/rotone.c
- 3-inter/inter.c
- 3-last_word/last_word.c
- 3-union/union.c
- 3-wdmatch/wdmatch.c
- 4-ft_atoi/ft_atoi.c
- 5-ft_range/ft_range.c
- 6-ft_itoa/ft_itoa.c
- 6-ft_split/ft_split.c

### C-Piscine-exam Level 02
- 2-0-ft_atoi/ft_atoi.c
- 2-0-ft_strdup/ft_strdup.c
- 2-0-inter/inter.c
- 2-0-last_word/last_word.c
- 2-0-reverse_bits/reverse_bits.c
- 2-0-swap_bits/swap_bits.c
- 2-0-union/union.c
- 2-1-alpha_mirror/alpha_mirror.c
- 2-1-max/max.c
- 2-3-wdmatch/wdmatch.c
- 2-4-do_op/do-op.c
- 2-4-print_bits/print_bits.c
- 2.6-is_power_of_2/is_power_of_2.c

Added missing expected files (subjects existed but source was missing):
- 2-5-ft_strcmp/ft_strcmp.c
- 2-5-ft_strrev/ft_strrev.c

## 2) Verification command used

From Exams Practice root:

```sh
find 'Exam02' 'C-Piscine-exam/Level 02' -type f -name '*.c' | sort | while IFS= read -r f; do
  echo "[CHECK] $f"
  cc -Wall -Wextra -Werror -c "$f" -o /tmp/examcheck.o || exit 1
done
```

Result: all files compile cleanly.

## 3) Concept map by exercise type

- Output-only string scans (aff_a, aff_z, rev_print, first_word, last_word):
  - Practice argument checking, pointer/index traversal, and write-based output.
- Alphabet transforms (rotone, rot_13, alpha_mirror):
  - ASCII range logic and character mapping without libc helpers.
- Set-like character filtering (inter, union):
  - Use a 256-size seen table for O(n) duplicate checks.
- Subsequence matching (wdmatch):
  - Two-pointer scan where order matters but contiguity does not.
- Core utility functions (ft_strlen, ft_swap, ft_strcmp, ft_strrev):
  - Fundamental pointer and array manipulation APIs.
- Numeric parsing and arithmetic (ft_atoi, do_op):
  - Whitespace/sign handling and integer operation dispatch.
- Bitwise practice (reverse_bits, swap_bits, print_bits, is_power_of_2):
  - Shifts, masks, nibble swapping, and power-of-two identity: n & (n - 1).
- Dynamic memory exercises (ft_strdup, ft_range, ft_itoa, ft_split):
  - Allocation sizing, ownership rules, and null-terminated data structures.

## 4) Useful compile/run commands per program task

Example pattern for program exercises:

```sh
cc -Wall -Wextra -Werror <file>.c -o <prog>
./<prog> "test input"
```

Concrete examples:

```sh
cc -Wall -Wextra -Werror Exam02/2-rot_13/rot_13.c -o rot_13
./rot_13 "My horse is Amazing."

cc -Wall -Wextra -Werror 'C-Piscine-exam/Level 02/2-4-do_op/do-op.c' -o do_op
./do_op "123" "*" "456"
```

For function-only exercises, compile as object file:

```sh
cc -Wall -Wextra -Werror -c Exam02/5-ft_range/ft_range.c
cc -Wall -Wextra -Werror -c 'C-Piscine-exam/Level 02/2-0-reverse_bits/reverse_bits.c'
```

## 5) Mentor notes for exam speed

- Always start by matching exact prototype from subject.
- For write-only exercises, keep one pass over input and one final newline.
- For string uniqueness tasks, a 256 lookup table is the fastest exam-safe pattern.
- For malloc tasks, compute size first, allocate once, then fill deterministically.
- For function-only tasks, avoid unnecessary includes and main functions.
