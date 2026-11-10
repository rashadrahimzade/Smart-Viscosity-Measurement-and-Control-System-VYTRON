# 🌊 CFD & Flow Analysis

This section presents numerical fluid flow simulations conducted using **Ansys Fluent** to analyze the hydrodynamic behavior, velocity profiles, and drag forces acting on the falling sphere within the viscometer column.

## 1. Simulation Setup & Boundary Conditions

| Property | Value |
|----------|-------|
| **Software** | Ansys Fluent |
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

## 3. Source Files

All CFD project files, mesh data, simulation results, and Ansys Fluent project files are located in:

```
Mechanical/CFD_Analysis/
```

This folder contains the complete Ansys Fluent simulation setup and results. The `docs/cfd-analysis.md` file provides only a summary of the key findings.

---

## 4. Related Files

- `Mechanical/CFD_Analysis/README.md` — CFD analysis readme
- `docs/cfd/cfd-analysis.md` — Alternative CFD documentation copy (if maintained separately)

> **Note:** Do not duplicate CFD simulation files in the `docs/` folder. Keep the source files in `Mechanical/CFD_Analysis/` and reference them from this document.
