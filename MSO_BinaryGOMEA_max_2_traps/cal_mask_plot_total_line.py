import matplotlib.pyplot as plt
import matplotlib.ticker as ticker
import numpy as np
import collections

def calculate_average_sizes(filename):
    """
    Reads a specified file and collects size data for each generation.
    """
    generation_sizes = {}
    try:
        with open(filename, 'r') as file:
            for line in file:
                if line.strip() == "111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111":
                    print("End of file reached")
                    break
                parts = line.split(',')
                if len(parts) == 2:
                    generation = int(parts[0].strip())
                    size = int(parts[1].strip())
                    if generation in generation_sizes:
                        generation_sizes[generation].append(size)
                    else:
                        generation_sizes[generation] = [size]
        return generation_sizes
    except Exception as e:
        print(f"Error processing file {filename}: {e}")
        return {}

def process_files(file_pattern, count):
    """
    Processes a series of files named according to a pattern, compiles all file data, and calculates a global average.
    """
    all_generations = {}
    for i in range(1, count + 1):
        filename = file_pattern.format(i)
        generation_sizes = calculate_average_sizes(filename)
        for generation, sizes in generation_sizes.items():
            if generation in all_generations:
                all_generations[generation].extend(sizes)
            else:
                all_generations[generation] = sizes

    return all_generations



def plot_and_save(generations_data):
    """
    Plots the average size per generation, annotates data points, and saves the plot to a PNG file.
    Ensures that only integer values are displayed on the x-axis.
    """
    # Ensure that we only have integer generations
    generations = [gen for gen in sorted(generations_data.keys()) if isinstance(gen, int)]
    average_sizes = [sum(generations_data[gen]) / len(generations_data[gen]) for gen in generations]

    plt.figure(figsize=(20, 14))  # Adjusting the figure size for better visibility
    plt.plot(generations, average_sizes, marker='o', linestyle='-', color='b', markersize=8)  # Larger markers
    # Annotate each point with larger font size
    for i, txt in enumerate(average_sizes):
        plt.annotate(f'{txt:.2f}', (generations[i], average_sizes[i]), textcoords="offset points",
                     xytext=(0,10), ha='center', fontsize=20, color='darkblue')
    plt.title('CycTrap: ell = 300, population = 60', fontsize=30)
    plt.xlabel('Generation', fontsize=16)
    plt.ylabel('Average Size', fontsize=16)
    plt.xticks(fontsize=16)  # Larger tick labels
    plt.yticks(fontsize=16)
    plt.grid(True)
    # Ensuring x-axis has only integer ticks
    plt.gca().xaxis.set_major_locator(ticker.MaxNLocator(integer=True))
    plt.savefig('average_sizes.png')



# File pattern and number of files
file_pattern = "./300_60_{}.txt"  # File pattern
number_of_files = 10  # Total number of files

# Process files and calculate global averages
global_generations_data = process_files(file_pattern, number_of_files)
# Plot and save the results to a PNG file
plot_and_save(global_generations_data)
