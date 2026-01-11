import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d.art3d import Poly3DCollection
import numpy as np

# Define base parallelogram
a = 9  # side along x
b = 8  # angled side
h = 6  # height between sides of length a

# Calculate angle and y-offset of side b
theta = np.arccos(h / b)
x_offset = b * np.sin(theta)
y_offset = b * np.cos(theta)

# Base corners
A = np.array([0, 0, 0])
B = np.array([a, 0, 0])
C = np.array([a + x_offset, y_offset, 0])
D = np.array([x_offset, y_offset, 0])

# Apex
base_center = (A + B + C + D) / 4
height = 5
apex = base_center + np.array([0, 0, height])

# Faces
faces = [[A, B, C, D], [A, B, apex], [B, C, apex], [C, D, apex], [D, A, apex]]  # base

# Plotting
fig = plt.figure()
ax = fig.add_subplot(111, projection="3d")

# Draw faces
ax.add_collection3d(
    Poly3DCollection(
        faces, facecolors="grey", linewidths=1, edgecolors="black", alpha=0.2
    )
)

# Dotted height line
ax.plot(
    [apex[0], base_center[0]],
    [apex[1], base_center[1]],
    [apex[2], base_center[2]],
    "k--",
)

# Font properties for the labels
font_properties = {"family": "Arial", "size": 15}

# Label sides of parallelogram
mid_AB = (A + B) / 2
mid_AD = (A + D) / 2
ax.text(mid_AB[0], mid_AB[1] - 1.5, -0.4, "9", color="black", fontdict=font_properties)
ax.text(
    mid_AD[0] + 9.5, mid_AD[1] - 0.5, -0.7, "8", color="black", fontdict=font_properties
)

# Label height of parallelogram
mid_height = (A + D) / 2 + np.array([0, -y_offset / 2, 0])
ax.plot(
    [9, 9], [mid_height[1], mid_height[1] + 6], [0, 0], color="black", linestyle="--"
)
ax.text(
    8, mid_height[1] + y_offset / 1.6, 0, "6", color="black", fontdict=font_properties
)

# Label pyramid height
ax.text(
    base_center[0] - 1.2,
    base_center[1] - 0.5,
    height / 3,
    "5",
    color="black",
    fontdict=font_properties,
)

# Calculate the maximum of the base and height values
max_value = max(a, b, h, height) * 1.5

# Set equal limits for all axes based on the maximum value
ax.set_xlim([0, max_value])
ax.set_ylim([0, max_value])
ax.set_zlim([0, max_value])  # Ensure enough space for the pyramid height

# Hide grid and axes
ax.grid(False)
ax.set_axis_off()

plt.show()
