# Digital Lowpass Filter
The digital lowpass filter is obtained by converting the transfer function of an analog RC lowpass filter to the discrete domain via a forward Euler discertization.

The analog lowpass filter transfer function:
> $$ H(s) = { Y(s) \over X(s) } = { 1 \over 1+sRC } $$

Where R is the resistance and C is the capacitance.

The forward Euler discretization:
> $$ s = { z-1 \over T_s } $$

Where T<sub>s</sub> is the system sampling time.

The updated transfer function in the z-domain:
> $$ H(z) = { Y(z) \over X(z) } = { T_s \over T_s+RC(1-z^{-1}) } $$

The discrete output:
> $$ y[n] = { T_s \over T_s+RC }x[n] + { RC \over T_s+RC }y[n-1] $$

RC can be replaced by the system time constant $ T_c $:
> $$ y[n] = { T_s \over T_s+T_c }x[n] + { T_c \over T_s+T_c }y[n-1] $$
