# Computation Pipeline

## Steps

1. Read inputs (S, K, σ, T, r)
2. Validate inputs against domain rules
3. Compute d1
4. Compute d2
5. Compute N(d1) and N(d2)
6. Compute discount factor → $e^{-rT}$
7. Compute call price → $S \cdot N(d_1) - K \cdot \text{discount} \cdot N(d_2)$
8. Compute put price → $K \cdot \text{discount} \cdot N(-d_2) - S \cdot N(-d_1)$
9. Print results

## Input Contract

The program prompts the user sequentially:

1. `Enter Stock Price (S):`
2. `Enter Strike Price (K):`
3. `Enter Volatility (σ):`
4. `Enter Time to Expiration (T):`
5. `Enter Risk-Free Rate (r):`

All inputs are read as floating-point values.

### Accepted Units

| Input | Unit | Example |
|-------|------|---------|
| S (stock price) | Dollars | 100.0 |
| K (strike price) | Dollars | 100.0 |
| σ (volatility) | Decimal | 0.20 = 20% |
| T (time to expiration) | Years | 1.0 = 1 year, 0.5 = 6 months |
| r (risk-free rate) | Decimal | 0.05 = 5% |

### Input Handling

For each input:
- If value is non-numeric → invalid
- If value violates domain rules → invalid
- If valid → accept and continue

On invalid input:
- Print: `Invalid input. Try again`
- Re-prompt for the same value

### Input Function

A reusable input unit (`getValidInput`) handles all input:
- Takes: prompt text
- Returns: validated double
- Behavior: displays prompt, reads input, validates, re-prompts until valid

## Rule Notes

- All percentage-based inputs must be entered as decimals (e.g., 20% → 0.20)
- Time must always be expressed in years
- Domain validation occurs before any computation
