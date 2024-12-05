import subprocess
import re
import matplotlib.pyplot as plt
import sys

png_name = sys.argv[1]

# 定義要執行的命令
# commands = [
#     ["./sweep", "12", "10", "0"],
#     ["./sweep", "24", "10", "0"],
#     ["./sweep", "36", "10", "0"],
#     ["./sweep", "48", "10", "0"],
#     ["./sweep", "60", "10", "0"],
# ]

# commands = [
#     ["./sweep", "60", "10", "0"],
#     ["./sweep", "120", "10", "0"],
#     ["./sweep", "180", "10", "0"],
#     ["./sweep", "240", "10", "0"],
#     ["./sweep", "300", "10", "0"],
#     ["./sweep", "360", "10", "0"],
#     ["./sweep", "420", "10", "0"],
    # ["./sweep", "480", "10", "0"],
    # ["./sweep", "540", "10", "0"],
    # ["./sweep", "600", "10", "0"],
# ]

# mktrap
commands = [
    # ["./sweep", "60", "10", "1"],
    # ["./sweep", "120", "10", "1"],
    # ["./sweep", "180", "10", "1"],
    # ["./sweep", "240", "10", "1"],
    # ["./sweep", "300", "10", "1"],
    # ["./sweep", "360", "10", "1"],
    # ["./sweep", "420", "10", "1"],
    # ["./sweep", "480", "10", "1"],
    # ["./sweep", "540", "10", "0"],
    ["./sweep", "600", "10", "0"],
]

# 初始化列表來存儲 NFE 結果和 population size
nfe_results = []
population_sizes = []

# 逐一執行命令並提取 NFE 結果
for cmd in commands:
    try:
        # 提取 population size（命令的第一個參數）
        population_size = int(cmd[1])
        population_sizes.append(population_size)

        # 使用 subprocess 執行命令並捕獲輸出
        result = subprocess.run(cmd, check=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        output = result.stdout.decode()
        
        # 使用正則表達式提取 NFE 值
        match = re.search(r"NFE:\s*([\d\.]+)", output)
        if match:
            nfe_value = float(match.group(1))
            nfe_results.append(nfe_value)
            print(f"Population Size {population_size}: Extracted NFE value: {nfe_value}")
        else:
            print("No NFE value found in output.")
    
    except subprocess.CalledProcessError as e:
        print(f"Command {' '.join(cmd)} failed with error:")
        print(e.stderr.decode())

# 繪製 NFE 結果的折線圖
plt.figure(figsize=(10, 6))
plt.plot(population_sizes, nfe_results, marker='o', linestyle='-', color='b', label="NFE")

# 在每個數據點上顯示 NFE 值，並調整字體大小和位置
for i, txt in enumerate(nfe_results):
    plt.text(population_sizes[i], nfe_results[i] + 0.8, f'{txt:.2f}', ha='center', va='bottom', fontsize=30)

# 設定圖表屬性
plt.xlabel("Problem Size", fontsize=30)
plt.ylabel("NFE", fontsize=30)
plt.xticks(population_sizes)  # 設定 X 軸刻度為指定的 population sizes
plt.legend()
plt.grid(True, linestyle='--', linewidth=0.5, color='gray')

# 顯示並儲存折線圖
plt.tight_layout()
plt.savefig(f'./png/{png_name}.png')
# plt.show()
