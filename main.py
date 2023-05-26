import subprocess
import matplotlib.pyplot as plt
from random import randint


def run_binary(path, command, size, seed):
    subprocess.call([path, command, str(size), str(seed)])


def read_file(filename: str):
    data = []
    with open(filename, 'r') as file:
        for line in file:
            size, time = line.strip().split(';')
            data.append((float(time), int(size)))
    return data


def generate_plot(data, name):
    sizes = [entry[0] for entry in data]
    times = [entry[1] for entry in data]

    plt.plot(times, sizes, label=name)
    plt.legend(loc='upper left')


if __name__ == '__main__':
    path = './bin/sorting'
    seed = randint(1, 1000)
    command = {
        "R": "radixsort",
        "H": "heapsort",
        "M": "mergesort",
        "Q": "quicksort",
        # "I": "insertionsort", # carroça
        # "S": "selectionsort", # carroça master
        # "B": "bubblesort", # carroça extreme
    }

    n = 10_000_000  # max vector
    i = int(n / 15)

    for i in range(i, n, i):
        for k in command.keys():
            run_binary(path, k, i, seed)

    for v in command.values():
        data = read_file(f'./{v}.csv')
        generate_plot(data, v)

    plt.xlabel('Tamanho do vetor')
    plt.ylabel('Tempo (s)')
    # plt.ticklabel_format(style='plain')
    plt.savefig('graphic.png', dpi=300)
