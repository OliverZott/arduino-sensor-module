import os
from pathlib import Path

root_dir = Path(__file__).resolve().parent
os.chdir(root_dir)

print(f"Path.cwd(): {Path.cwd()}")
print(f"Path(__file__): {Path(__file__).resolve().parent }")


print("\n============================================================ MyPy ============================================================")
# mypy only checks the code by default and does not apply any changes.
os.system("mypy --exclude venv .")


print("\n============================================================ Ruff Linter ============================================================")
os.system("ruff check .")  # --check


print("\n============================================================ Ruff Formatter ============================================================")
os.system("ruff format --check .")
