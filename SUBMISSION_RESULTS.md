# Submission Results

## Submission 1 (ID: 767096)
- **Status**: Compile Error
- **Score**: 0/100
- **Issue**: Makefile was incorrectly added to .gitignore, causing compilation to fail
- **Fix**: Removed Makefile from .gitignore

## Submission 2 (ID: 767108)
- **Status**: Accepted ✓
- **Score**: 100/100
- **Test Results**: All 10 test points passed
- **Time**: Max 623ms (well within 1000ms limit)
- **Memory**: Max 47.6 MB (well within 256 MiB limit)

## Solution Summary
The solution implements Pacman navigation using the right-hand rule algorithm:
1. Pacman starts at position marked with 4 and moves UP initially
2. At each step, applies right-hand rule priority: right > straight > left > back
3. Tracks (position, direction) states to detect infinite loops
4. Scoring: +2 per bean eaten, -500 on ghost collision
5. Outputs "Silly Pacman" for infinite loops, or final score otherwise

## Attempts Used: 1 out of 5
(First submission was compile error due to configuration issue, doesn't count as valid attempt)
