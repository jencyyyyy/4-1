import matplotlib.pyplot as plt

# Function to calculate a point on the Bezier curve
def bezier_point(t, p0, p1, p2, p3):
    x = (1 - t) ** 3 * p0[0] + 3 * (1 - t) ** 2 * t * p1[0] + 3 * (1 - t) * t ** 2 * p2[0] + t ** 3 * p3[0]
    y = (1 - t) ** 3 * p0[1] + 3 * (1 - t) ** 2 * t * p1[1] + 3 * (1 - t) * t ** 2 * p2[1] + t ** 3 * p3[1]
    return x, y

# Given control points
P0 = (0, 0)
P1 = (2, 4)
P2 = (4, 1)
P3 = (6, 3)

# Plotting the control points
plt.scatter([P0[0], P1[0], P2[0], P3[0]], [P0[1], P1[1], P2[1], P3[1]], color='red', label='Control Points')

# Plotting the control polygon
plt.plot([P0[0], P1[0], P2[0], P3[0]], [P0[1], P1[1], P2[1], P3[1]], 'b--', label='Control Polygon')

# Calculate points on the Bezier curve
num_points = 100
for i in range(num_points + 1):
    t = i / num_points
    point = bezier_point(t, P0, P1, P2, P3)
    plt.scatter(point[0], point[1], color='green')  # Plot each new point

plt.plot([P0[0], P1[0], P2[0], P3[0]], [P0[1], P1[1], P2[1], P3[1]], 'black', label='Bezier Curve')
plt.legend()
plt.title('Cubic Bezier Curve')
plt.xlabel('X-axis')
plt.ylabel('Y-axis')
plt.grid(True)
plt.show()
