# Test Cases

## Case 1 — At The Money

| Input | Value |
|-------|-------|
| S | 100 |
| K | 100 |
| σ | 0.20 |
| T | 1.0 |
| r | 0.05 |

Expected: call ≈ 10.45, put ≈ 5.57

## Case 2 — In The Money

| Input | Value |
|-------|-------|
| S | 120 |
| K | 100 |
| σ | 0.20 |
| T | 1.0 |
| r | 0.05 |

Expected: call price increases, put price decreases

## Case 3 — Out Of The Money

| Input | Value |
|-------|-------|
| S | 80 |
| K | 100 |
| σ | 0.20 |
| T | 1.0 |
| r | 0.05 |

Expected: call price decreases, put price increases

## Case 4 — Higher Volatility

| Input | Value |
|-------|-------|
| S | 100 |
| K | 100 |
| σ | 0.40 |
| T | 1.0 |
| r | 0.05 |

Expected: both call and put prices increase

## Case 5 — Shorter Time

| Input | Value |
|-------|-------|
| S | 100 |
| K | 100 |
| σ | 0.20 |
| T | 0.25 |
| r | 0.05 |

Expected: verify numerically using calculator

## Invalid Cases

| Case | Input | Expected |
|------|-------|----------|
| A | S = 0 | Reject |
| B | σ = 0 | Reject |
| C | T < 0 | Reject |
| D | input = "abc" | Reject and re-prompt |
