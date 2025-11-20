import random
import numpy as np
from typing import List, Tuple, Optional
from pprint import pprint
import seaborn as sns
import matplotlib.pyplot as plt

class ImageH:
    """ Base class for image processing, with a method to insert a sample image."""
    def __init__(self):
        self.data: List[List[float]] = []

    def insert_sample(self, size: int = 1) -> List[List[float]]:
        """Insert a sample image into the object.
        Args:
            size: The size of the image to generate.
        Returns:
            The generated image (NxN List of lists).
        """
        unique_numbers = random.sample(range(size**2 + 1), size * size)
        self.data = [unique_numbers[i*size:(i+1)*size] for i in range(size)]
        return self.data
    
    def plot_sample_heatmap(self):
        """Plot the sample image as a heatmap."""
        sns.heatmap(self.data, annot=True, fmt=".0f", cmap='viridis')
        plt.show()

class ImageProcessor(ImageH):
    def __init__(self):
        super().__init__()

    def GetHighestPixel(self) -> Optional[Tuple[int, int]]:
        """Find the index of the highest pixel in the image."""
        
        high_values_indices = []
        highest_value = float('-inf')
        highest_value_index = None

        try:
            sorted_data = self.FlattenSortData(self.data)
            highest_value = sorted_data[-1]
            
            ################################
            #
            #
            #
            #
            #
            #
            ################################
            return highest_value_index
        
        except Exception as e:
            print(f"An error occurred: {e}")
            return None
        
    def GetHighestPixelNumpy(self) -> Optional[Tuple[int, int]]:
        """Find the index of the highest pixel in the image."""
        try:
            data_array = np.array(self.data)
            index = np.unravel_index(np.argmax(data_array, axis=None), data_array.shape)
            return index
        except Exception as e:
            print(f"An error occurred: {e}")
            return None


    @staticmethod
    def FlattenSortData(data: List[List[float]]) -> List[float]:
        """Flatten and sort the data."""
        flattened_data = [pixel for row in data for pixel in row]
        return sorted(flattened_data)

# Example usage
if __name__ == "__main__":
    data_sample = ImageProcessor()
    data_sample.insert_sample(20)
    
    # result = data_sample.GetHighestPixel()
    result_numpy = data_sample.GetHighestPixelNumpy()


    # print(f"Index of the highest value in the top 0.5%: {result}")
    print(f"Index of the highest value in the top 0.5% (numpy): {result_numpy}")
    # pprint(f"Data Sample: {data_sample.data}")
    data_sample.plot_sample_heatmap()
    # print(f"Value of the highest pixel: {data_sample.data[result[0]][result[1]]}")
