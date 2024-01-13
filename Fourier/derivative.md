# How to derive a function exploiting DFT
By writing a function $f(x)$, evalueted in the site of the lattice $x_n=na$, as its IDFT
$$f(x_n) = \frac{1}{N}\sum_{k=0}^{N-1}\hat{f}_ke^{2\pi i\frac{nk}{N}}$$
**Notice that**: $k$ goes from 0 to N is the usual convention (e.g. python). It is a convention, because you can relate that the exponential associated to $k=-1$ is **the same** associated to $k=N-2$. In general $k$ and $k\pm N$ have the same exponential.

If you **naively** derive respect to $x=na$ the above expression, you get down from the exponential a factor $i\frac{2\pi kn}{N}$, so you **naively** expect
$$f'(x_n) = \frac{1}{N}i\frac{2\pi}{Na}\sum_{k=0}^{N-1}k\hat{f}_ke^{2\pi i\frac{nk}{N}}$$

So you calculate the coefficients $\hat{f}_k$ by calculating DFT, then you multiply **each** by **its index** k and then you calculate IDFT.
**But this does not work!!!**

The right expression is
$$f'(x_n) = \frac{1}{N}\sum_{k=0}^{N-1}(iq_k)\hat{f}_ke^{2\pi i\frac{nk}{N}}$$
where
$$q_k = \frac{2\pi}{Na}k\quad\text{if } k=0,1,..., N/2-1$$
$$q_k = \frac{2\pi}{Na}(k-N)\quad\text{if } k=N/2,..., N-1$$

You can the array $q_k$ ($k$ is the index of the array $k=0,1,...,N-1$), without the factor $2\pi/a$, with the function np.fft.fftfreq(N).

**I Cannot get why the right formula is that**