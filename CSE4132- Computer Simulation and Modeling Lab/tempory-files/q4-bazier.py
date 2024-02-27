import matplotlib.pyplot as plt

# Define control points (adjust these coordinates as needed)
P0 = (10, 10)
P1 = (50, 80)
P2 = (80, 30)
P3 = (120, 90)

# Function to calculate a point on the Bezier curve for a given t value
def bezier_point(t, P0, P1, P2, P3):
    x = (1-t)**3 * P0[0] + 3*(1-t)**2 * t * P1[0] + 3*(1-t) * t**2 * P2[0] + t**3 * P3[0]
    y = (1-t)**3 * P0[1] + 3*(1-t)**2 * t * P1[1] + 3*(1-t) * t**2 * P2[1] + t**3 * P3[1]
    return x, y

# Generate points on the curve and display each one
curve_points = []
for t in range(0, 101):
    x, y = bezier_point(t/100, P0, P1, P2, P3)
    curve_points.append((x, y))
    print(f"Point for t={t/100}: ({x:.2f}, {y:.2f})")

# Plot the control points and curve
plt.plot([p[0] for p in curve_points], [p[1] for p in curve_points], 'b-')
plt.plot(*zip(P0, P1, P2, P3, P0), 'ro--')  # Plot control points with a closed loop
plt.xlabel("X")
plt.ylabel("Y")
plt.title("Cubic Bezier Curve")
plt.legend()
plt.grid()
plt.show()
