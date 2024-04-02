## Cross product norm gives area

If you consider the parallelogram spanned by two vectors $v_1, v_2 \in R^2$, you can see that the area of it is

$$A = ||v_1||\cdot||v_2||\cdot\sin\alpha$$

![ParallelogramAngleAlpha](imm/a.png?raw=true)

But this formula is the same for the norm of the cross product
$$A = ||v_1\times v_2||$$
Where, in order for the cross product to be well defined, you need to add to each vector a **null third component**
$$v_1\in R^2\rightarrow (v_1; 0)\in R^3$$

From the right-hand rule, the cross product is directed on the axis orthogonal to the paper.
So the norm of the product is the modulus of the $z$ component.
$$A = ||v_1 \times v_2|| = |(v_1 \times v_2)_z|$$
And we know that this component can be computed as the determinant
$$(v_1 \times v_2)_z = det(v_{1x}, v_{1y}; v_{2x}, v_{2y})$$

(where "," means on the same row and ";" goes to a new row)

But you can see that, for a 2D matrix $M$, the determinant coincides with the one of its transpose, because transposition of a 2D matrix just exchanges the off-diagonal entries.
So

$$(v_1 \times v_2)_z = det(v_{1x}, v_{2x}; v_{1y}, v_{2y}) = det(v_1, v_2)$$

To conclude, we can calculate the area of the parallelogram spanned by two 2D vectors as

$$A = ||v_1 \times v_2|| = det(v_1, v_2)$$

#### Scaling factor for areas
If we apply a linear map (multiply by a matrix) $M$ both the vectors, the area of the **new** parallelogram spanned by $Mv_1, Mv_2$ will be

$$A = det(Mv_1, Mv_2) = det(M(v1, v2)) = det(M)\cdot det(v_1, v_2)$$

So the application of a linear map brings to a rescaling of the areas of a factor $det(M)$.

## Calculating area of the circle
### Integrate characterstic function
You can calculate the area of the circle by integrating in the whole $\mathcal{R^2}$
$$A = \int\int_{R^2} dxdy\quad \chi(x,y) = \int_{-R}^Rdx\int_{-\sqrt{R^2-x^2}}^{\sqrt{R^2-x^2}}dy$$
### Exploit simmetries: Divide in rings and fragments of rings
You can divide the circle in **concentric rings** and calculate the circle area by summing the ones of _all_ the concentric rings.

You can then divide each ring in additional fragments, as in the picture.

![Division in fragmets of circle](imm/circular%20fragments.png?raw=true)

The area of each fragment is $dA = rd\theta dr$, so then the integral, **that is a SUM**, is the sum over all the fragments
$$A = \int_0^{2\pi}\int_0^Rrd\theta dr = \pi R^2$$

### Perform the polar change of variables

Above we've seen the most reasonable way of calculating the area of the circle, but our discussion is about the **determinant of the jacobian** that rises when you make a change of variable when computing an integral.

So let's make a change of variable from cartesian to polar coordinates.

$$(x, y)\rightarrow (r, \theta)$$

Each point of the circle is now mapped inside a rectangule, as shown here

![Circle to rectangule. Enhancing the same fragment in both images](imm/change%20of%20vars.png?raw=true)

You can see that a small circular fragment is mapped in a small rectangule by the change of variables.

Now, **very naively**, you could think to compute the integral by summing all the small rectangules (as you did before with all the **corresponding** circular fragments).
The area of each small rectangule is $dA = d\theta dr$ and **summing** all them **means performing an integral**

$$\int_0^{2\pi}\int_0^R d\theta dr = 2\pi R \neq \pi R^2$$
so this naive method is **WRONG**, but **WHY???**



The reason is that, **if the first** integration (where you sum the circular fragments) **is correct**, then the second integration, that sums **over the same objects** (as there is a 1-1 correspondance between circular fragments and rectangules) **but with a different area** cannot _still_ be correct!

Anyway, there is a way of computing the integral by performing a change of variable, **but we have to rescale** the area of the small rectangule such that it **will match the area of the corresponding** circular fragments.

## How the determinant of the Jacobian rises

You can see from the previous image, that the map that maps a small rectangule in its corresponding circular fragments, is the map that maps

$$(r, \theta)\rightarrow(x, y)$$
$$x = r\cos\theta\\y = r\sin\theta$$

as this **is the inverse** of the change of variables we made.

If the rectangule size (and so both $dr, d\theta$) goes to zero, then, **for the mapping of a small rectangule** in its circular fragment, we can consider the **linearized version** of the map (first order Taylor expansion)

$$(\bar{r}+dr,\bar{\theta}+d\theta) \rightarrow (\bar{x}, \bar{y}) + J (dr, d\theta)$$

Where writing the $+dr, +d\theta$ in the above formula is a way for writing a general formula, thar holds for **any** point inside the sall rectangule.
And the $J$ is the **Jacobian matrix of the map** $(r,\theta)\rightarrow (x,y)$.

If you see how the corners of the small rectangle are mapped by the **linearized** map; or even simply if you appreciate that the map is linear (so it is **just a rotation + shrink** transformation), this is **into what** the small rectangle is mapped:

![Deformation shrink](imm/b.png?raw=true)

Now we know that the area of this parallelogram is just scaled by a factor $\det J$, and we also know that $\det J = \det J^{-1}$ as
$$1 = \det 1 = \det JJ^{-1} = \det J \det J^{-1}$$

so we have to rescale the area of each small rectangle by a factor that is the dererminant of the jacobian of the change of variable.

### Why can we linearize the map?

It is ok to consider the linearized map, because when you make an integral, you are taking the limit where the small fragment size goes to zero, so the approximation error (that you make by considering the linearized map) goes to zero.

## Conceptual comment on the RESCALING of the integration element

It is **not correct saying** that 
"the integration element changes size when you change variable", for many reasons:
- The choice of the size of the integration element is arbitrary, as the choice of _how small_ $dr, d\theta$ are is arbitrary.
- The integration element before is $dxdy$ and after is $drd\theta$, but we are not comparing those two, but a circular fragment with the _corresponding_ small rectangule $drd\theta$.

The only thing we can say, is that 
    
"Fixed a point $r,\theta$ and fixed the small values $drd\theta$, then the **region of the circle** $(r+dr,\theta+d\theta)$ is mapped by the change of variables in a region of smaller area."

Where we can say "**of smaller area**" (we can **compare** the areas) because the areas of the two regions are described by the **same values** $r,\theta,dr,d\theta$.

That's **because there is an arbitrariness in the choice of $dr, d\theta$** and so it makes no sense saying they are "too small and so to be corrected"


## To keep in mind

There is always a way of calculating the area of a shape by exploiting the symmetries of the shape. This idea brings to divide the shape in small fragments in a way that respects the simmetries, then you sum them (as we have seen with the circular rings).

If you, instead, make a change of variable (in such a way that you still **exploit the same simmetries**), as the "simmetries method" works, in order for the other method to work, you have to rescale the "new" small fragments such that they reach the same area of the corresponding "simmetries method" fragments.