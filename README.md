# Black-Scholes Option Pricer

A C++ command-line tool that calculates European-style option prices using the Black-Scholes model. Given market inputs like stock price, strike price, volatility, time to expiration, and risk-free interest rate, it computes the theoretical value of both call and put options.

## How It Works

The Black-Scholes model estimates what an option should be worth by taking in market inputs. It assumes:

- Price fluctuations are constant throughout the stock's life
- The asset pays no dividends prior to expiration
- The option can only be exercised at expiration (European style)
- Prices reflect all available information
- Assets follow a log-normal distribution
- Markets operate continuously
- No transaction fees

## Build & Run

```bash
mkdir -p cmake-build-debug && cd cmake-build-debug
cmake ..
cmake --build .
./black_scholes_option_pricer
```

## Usage

The program prompts for five inputs sequentially:

```
Enter Stock Price (S): 100
Enter Strike Price (K): 100
Enter Volatility (σ): 0.20
Enter Time to Expiration (T): 1.0
Enter Risk-Free Rate (r): 0.05
```

Output:

```
Call: 10.4506
Put: 5.57352
Verification
Call - Put -> 4.87707
Stock Price - Discounted Strike Price -> 4.87707
```

The verification step confirms [put-call parity](https://en.wikipedia.org/wiki/Put%E2%80%93call_parity): `Call - Put` should equal `S - K·e^(-rT)`.

All inputs must be positive numbers. Invalid or non-numeric input is rejected with a re-prompt.

## Inputs

| Variable | Description | Unit | Example |
|----------|-------------|------|---------|
| S | Current stock price | Dollars | 100.0 |
| K | Strike price | Dollars | 100.0 |
| σ | Volatility | Decimal | 0.20 = 20% |
| T | Time to expiration | Years | 0.5 = 6 months |
| r | Risk-free interest rate | Decimal | 0.05 = 5% |

## Documentation

See the [docs](docs/) folder for detailed information on the math, computation pipeline, test cases, and resources.

## Resources

- [Black-Scholes Model Explained (CMC Markets)](https://www.cmcmarkets.com/en-gb/options-trading/what-is-the-black-scholes-model)
- [An Intuitive Explanation of Black-Scholes](https://gregorygundersen.com/blog/2024/09/28/black-scholes/)
