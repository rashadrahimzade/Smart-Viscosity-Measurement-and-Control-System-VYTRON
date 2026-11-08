\# 🌊 Computational Fluid Dynamics (CFD) \& Flow Analysis



This section presents the numerical fluid flow simulations conducted to analyze the hydrodynamic behavior, velocity profiles, and drag forces acting on the falling sphere within the viscometer column.



\---



\### 🔬 Simulation Setup \& Boundary Conditions



\* \*\*Flow Regime:\*\* Laminar Flow (Low Reynolds number regime, $Re \\ll 1$, adhering to Stokes' Law assumptions).

\* \*\*Fluid Domain:\*\* Cylindrical fluid column with wall-boundary interactions to evaluate the wall-effect factor.

\* \*\*Mesh \& Discretization:\*\* Refined inflation layers along the sphere surface to capture boundary layer velocity gradients accurately.

\* \*\*Boundary Conditions:\*\*

&#x20; \* \*\*No-Slip Condition:\*\* Applied to the sphere wall and the outer column cylinder.

&#x20; \* \*\*Inlet / Outlet:\*\* Defined relative velocity field corresponding to terminal falling speed.



\---



\### 📊 Key Verification \& Findings



\* \*\*Drag Force Comparison:\*\* Simulated hydrodynamic drag force was cross-verified against the analytical Stokes' Law equation ($F\_d = 6\\pi \\mu r v$).

\* \*\*Wall-Effect Evaluation:\*\* Quantified the velocity retardation caused by column wall proximity, validating the empirical correction factors ($f$) applied in system firmware.

\* \*\*Visual Output:\*\*

&#x20; \* Velocity contours demonstrating the wake formation behind the falling sphere.

&#x20; \* Pressure distribution highlights peak stagnation pressure at the leading edge.

