# Black-Scholes Math

## Variables

- $S$ → Current Stock Price
- $K$ → Exercise (Strike) Price
- $T$ → Time to Expiration (in years)
- $r$ → Risk-Free Interest Rate
- $\sigma$ → Volatility

## Domain Rules

| Variable | Constraint | Reason |
|----------|-----------|--------|
| S | > 0 | Required for ln(S/K) |
| K | > 0 | Required for ln(S/K) |
| σ | > 0 | Appears in denominator |
| T | > 0 | √T appears in denominator |
| r | ∈ ℝ | Any real number |

## Formulas

### Call Price

$$
V_c = S \cdot N(d_1) - K \cdot e^{-rT} \cdot N(d_2)
$$

### Put Price

$$
V_p = K \cdot e^{-rT} \cdot N(-d_2) - S \cdot N(-d_1)
$$

### d1

$$
d_1 = \frac{\ln\left(\frac{S}{K}\right) + \left(r + \frac{1}{2}\sigma^2\right)T}{\sigma\sqrt{T}}
$$

### d2

$$
d_2 = d_1 - \sigma\sqrt{T}
$$

### Normal CDF

$$
N(x) = \frac{1}{2}\left(1 + \operatorname{erf}\left(\frac{x}{\sqrt{2}}\right)\right)
$$

## Calculators

- [Normal Distribution Calculator](https://stattrek.com/online-calculator/normal)
- [Wolfram Alpha](https://www.wolframalpha.com/)
