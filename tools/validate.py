from pathlib import Path
import json,subprocess
root=Path(__file__).resolve().parents[1]
json.loads((root/"sample-data/example.json").read_text())
subprocess.run(["g++","-std=c++17","-Wall","-Wextra","-Werror","tests/policy_test.cpp","-o","/tmp/maintenance-test"],cwd=root,check=True)
subprocess.run(["/tmp/maintenance-test"],check=True)
print("Warmup, baseline comparison, consecutive detection, reset, NaN, negative and overcurrent passed")
