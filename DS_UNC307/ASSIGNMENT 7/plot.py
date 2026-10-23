from pathlib import Path
import os
os.chdir(Path(__file__).resolve().parent)
import pandas as pd
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
 
df = pd.read_csv("complexity_1_to_100.csv")
 
# ---------- Graph 1: O(1), O(log n), O(sqrt n), O(n), O(n log n) for n = 1..100 ----------
fig, ax = plt.subplots(1, 2, figsize=(11, 4.6))
curves = [("O(1)", "O(1)"), ("O(logn)", "O(log n)"), ("O(sqrtn)", "O(sqrt n)"),
          ("O(n)", "O(n)"), ("O(nlogn)", "O(n log n)")]
for a in ax:
    for col, lab in curves:
        a.plot(df["n"], df[col], label=lab, linewidth=1.8)
    a.set_xlabel("n")
    a.set_ylabel("Number of operations")
    a.grid(True, alpha=0.3)
ax[0].set_title("Graph 1: n = 1 to 100")
ax[0].legend()
ax[1].set_ylim(0, 15)                      # zoom in so the slow curves are visible
ax[1].set_title("Zoom (y from 0 to 15)")
plt.tight_layout()
plt.savefig("graph1.png", dpi=150)
plt.close()
 
# ---------- Graph 2: O(n^2) and O(n^3) for n = 1..50 ----------
small = df[df["n"] <= 50]
plt.figure(figsize=(7, 4.6))
plt.plot(small["n"], small["O(n^2)"], label="O(n^2)", linewidth=1.8)
plt.plot(small["n"], small["O(n^3)"], label="O(n^3)", linewidth=1.8)
plt.xlabel("n")
plt.ylabel("Number of operations")
plt.title("Graph 2: O(n^2) and O(n^3) for n = 1 to 50")
plt.legend()
plt.grid(True, alpha=0.3)
plt.tight_layout()
plt.savefig("graph2.png", dpi=150)
plt.close()
