# Any unitary operator can be expressed as $U=e^{iH}$ where H is Hermitian

If $U$ is unitary, then its eigenvalues are _phases_ $e^{i\varphi_n}$ and so, in its eigenvectors basis it is a diagonal matrix, with only phases on the diagonal.
So, if $D$ is the operator that diagonalizes $U$,
$$U = De^{i\phi}D^{-1}$$
where $\phi$ is a diagonal matrix with the eigenvalues ${\varphi_n}$ as diagonal elements. In this way
$e^{i\phi} = \sum_n\frac{(i\phi)^n}{n!}$ is diagonal, with diagonal elements $e^{i\phi_n}$.

If you explicit $e^{i\phi} = \sum_n\frac{(i\phi)^n}{n!}$ inside $U = De^{i\phi}D^{-1}$, then
$$U = D\sum_n\frac{(i\phi)^n}{n!}D^{-1}$$

now observe that $D(i\phi)^2D^{-1} = D(i\phi)(i\phi)D^{-1}$ and if we insert an identity $1 = D^{-1}D$ between the two terms $(i\phi)$, you get
$$D(i\phi)^2D^{-1} = D(i\phi)D^{-1}D(i\phi)D^{-1} = (D(i\phi)D^{-1})^2$$

In general, you can write
$$D(i\phi)^nD^{-1} = (D(i\phi)D^{-1})^n$$
and so
$$U = \sum_n\frac{1}{n!}\big(D(i\phi)D^{-1}\big)^n = e^{i(D\phi D^{-1})}$$

Now it remains to proove that $H = D\phi D^{-1}$ is hermitian.

As $U$ is unitary, it follows that $UU^{\dagger} = 1$, so $U = (U^{\dagger})^{-1}$ and $U^{\dagger} = e^{-iH^{\dagger}}$.
So 
$$e^{iH} = (e^{-iH^{\dagger}})^{-1} = e^{iH^{\dagger}}$$
if we expand both exponentials
$$\sum_n\frac{(iH)^n}{n!} = \sum_n\frac{(iH^{\dagger})^n}{n!}$$

so $H=H^{\dagger}$.

## General statement
Notice that we find that $U$ can, in _any basis_, be expressed as an exponential of an operator, by observing it is so in its eigenvectors basis.

In particular we found that if, in the eigenvectors basis, $U$ can be expressed as $f(\phi) = e^{i\phi}$, then, in _any basis_, $U = f(D\phi D^{-1})$, where D is the matrix diagonalizing $U$.

### In general
If $U = f(\phi)$ in a certain basis and $f$ is **analytical**, then in any other basis connected with the former one by the matrix $D$, the matrix $U$ has this shape
$$U' = DUD^{-1} = f(D\phi D^{-1})$$

The proof follows by expanding $f(\phi)$ with is Taylor series as done before with the exponential.