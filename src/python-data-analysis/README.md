# Python data analysis

## Prerequisites

### Environment

Generate virtual environment and install packages.

```bash
# Create/activate/deactivate venv
python -m venv venv
.\venv\Scripts\activate
source venv/bin/activate
.\venv\Scripts\deactivate

# Install packages with activated env and check
python -m pip install --upgrade pip
pip install --upgrade -r ./requirements.txt 
pip list

# Freeze and Upgrade current packages  
pip freeze > pip_list.txt   
pip install --upgrade --force-reinstall -r requirements.txt
```

### .env file

Generate .env file if needed e.g. for data path.

- `DATA_BASE_PATH=c:/folder/folder/data/`
