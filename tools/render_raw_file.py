import numpy as np
import matplotlib.pyplot as plt

# Define image properties
width, height = 400, 400
num_channels = 3  # RGB

file_path = "../build/render.raw"  # Update this to your actual file path
raw_data = np.fromfile(file_path, dtype=np.uint8)

# Reshape and visualize the image
image = raw_data.reshape((height, width, num_channels))

# Display the image
plt.imshow(image)
plt.axis("off")
plt.title("Ray Tracer Visualizer")
plt.show()
