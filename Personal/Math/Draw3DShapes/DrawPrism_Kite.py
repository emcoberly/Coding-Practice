import matplotlib.pyplot as plt
import numpy as np
from mpl_toolkits.mplot3d.art3d import Poly3DCollection, Line3DCollection

# Kite diagonal lengths
d1 = 6  # shorter diagonal
d2 = 8  # longer diagonal
d2_part1 = 4  # first part of the longer diagonal
d2_part2 = 4  # second part of the longer diagonal
prism_height = 10  # height of the prism

# Vertices of the kite in the xy-plane (base of the prism)
v0 = (-d1 / 2, 0, 0)  # Left point of shorter diagonal
v1 = (d1 / 2, 0, 0)  # Right point of shorter diagonal
v2 = (0, d2_part1, 0)  # Upper point of longer diagonal (first part)
v3 = (0, -d2_part2, 0)  # Lower point of longer diagonal (second part)

# Collect vertices of the kite (base of the prism)
kite_vertices = [v2, v0, v3, v1]

# Top vertices of the prism (same as the base, but with z = prism_height)
top_vertices = [(x, y, prism_height) for (x, y, z) in kite_vertices]

# Faces of the prism
faces = [
    kite_vertices,  # Bottom kite face
    top_vertices,  # Top kite face
    [
        kite_vertices[0],
        kite_vertices[1],
        top_vertices[1],
        top_vertices[0],
    ],  # Side face 1 (front)
    [
        kite_vertices[1],
        kite_vertices[2],
        top_vertices[2],
        top_vertices[1],
    ],  # Side face 2 (right)
    [
        kite_vertices[2],
        kite_vertices[3],
        top_vertices[3],
        top_vertices[2],
    ],  # Side face 3 (back)
    [
        kite_vertices[3],
        kite_vertices[0],
        top_vertices[0],
        top_vertices[3],
    ],  # Side face 4 (left)
]

# Create figure
fig = plt.figure()
ax = fig.add_subplot(111, projection="3d")

# Draw the prism
prism = Poly3DCollection(
    faces, facecolors="grey", linewidths=0.5, edgecolors="black", alpha=0.2
)
ax.add_collection3d(prism)

# Dotted line for the shorter diagonal (d1)
ax.plot(
    [v0[0], v1[0]],
    [v0[1], v1[1]],
    [v0[2], v1[2]],
    linestyle="--",
    color="black",
    linewidth=1,
)

# Dotted line for the longer diagonal (d2)
ax.plot(
    [v2[0], v3[0]],
    [v2[1], v3[1]],
    [v2[2], v3[2]],
    linestyle="--",
    color="black",
    linewidth=1,
)

# Label the diagonals
label_font = {"fontname": "Arial", "fontsize": 12}

# Add custom labels for the diagonals at specified positions
ax.text(-1.25, 0.5, 0, f"{d1}", color="black", ha="center", va="center", **label_font)
ax.text(-0.5, -1, 0, f"{d2}", color="black", ha="center", va="center", **label_font)
ax.text(
    0,
    5,
    prism_height / 2,
    f"{prism_height}",
    color="black",
    ha="center",
    va="center",
    **label_font,
)

# Add right-angle marker in quadrant 1 (top right corner)
marker_size = 0.75  # Side length of the right angle marker
right_angle_marker = [
    # Right angle corner at (0, 0) with the marker size 0.75
    [0, 0, 0],
    [marker_size, 0, 0],  # Horizontal line
    [marker_size, 0, 0],  # Start vertical line
    [marker_size, marker_size, 0],  # Vertical line
    [marker_size, marker_size, 0],  # Return to horizontal
    [0, marker_size, 0],  # Close the square
]

# Plot the right-angle marker lines
right_angle_lines = Line3DCollection([right_angle_marker], colors="black", linewidths=1)
ax.add_collection3d(right_angle_lines)

# Set axis limits
max_extent = max(d1, d2, prism_height)
ax.set_xlim(-max_extent / 2, max_extent / 2)
ax.set_ylim(-max_extent / 2, max_extent / 2)
ax.set_zlim(0, prism_height + 3)

# Set equal aspect ratio for all axes (x, y, z)
ax.set_box_aspect([1, 1, 1])  # This will ensure uniform scaling

# Remove axes, ticks, and grid
ax.set_xticks([])
ax.set_yticks([])
ax.set_zticks([])
ax.set_axis_off()

plt.show()
