# 🌊 CFD & Flow Analysis

This section presents numerical fluid flow simulations conducted to analyze the hydrodynamic behavior, velocity profiles, and drag forces acting on the falling sphere within the viscometer column.

## 1. Simulation Setup & Boundary Conditions

| Property | Value |
|----------|-------|
| **Flow Regime** | Laminar Flow (Low Reynolds number regime, Re << 1, adhering to Stokes' Law assumptions) |
| **Fluid Domain** | Cylindrical fluid column with wall-boundary interactions to evaluate the wall-effect factor |
| **Mesh & Discretization** | Refined inflation layers along the sphere surface to capture boundary layer velocity gradients accurately |
| **Boundary Conditions** | No-Slip Condition: Applied to the sphere wall and outer column cylinder. Inlet/Outlet: Defined relative velocity field corresponding to terminal falling speed. |

## 2. Key Verification & Findings

- **Drag Force Comparison**: Simulated hydrodynamic drag force was cross-verified against the analytical Stokes' Law equation (F_d = 6πμrv).
- **Wall-Effect Evaluation**: Quantified the velocity retardation caused by column wall proximity, validating the empirical correction factors (f) applied in system firmware.
- **Visual Output**:
  - Velocity contours demonstrating wake formation behind the falling sphere.
  - Pressure distribution highlights peak stagnation pressure at the leading edge.
