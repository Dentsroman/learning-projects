# Project
This project contains the automated testcases for the different projects in the repo

## Run guide

### For preset cookie usage:
python helpers/contexts/cookies_context.py && pytest /tests/testfolder

### Possible arguments:
--workers: how many workers (processes) will be running at the same time. By default, 1

--tests-per-worker: how many tests per worker (threads). By default, 1

--reruns: If a testcase fails it will be executed again, with a max of times specified. By default, 3

--junitxml: Generate a xml file with the results in junit format, you must inform the name of the file, "results.xml" by default

--devices: Only allowed for components tests, it will run the components tests simulating the browser of the specified device, "iPhone 11 Pro landscape" by default

--browsers: Only allowed for components tests, it will run the components tests with the specified browsers, separated by coma, chromium by default

--headless: It can contain True or False, if false, the testcases will run without UI. By default, is set to True

--slow_motion: You can insert a delay between every action in your browser, the value must be specified in milliseconds, by default is se to 0 (no delay)

--pve: You can select the pve environment, by default is set to "DEV" if you want to select your PVE just send the number (06 for example). Make sure the urls of your PVE are added into file ./data/urls.json

### Examples:
pytest tests/components --workers 2 --tests-per-worker 2 --junitxml=results.xml --devices="iPhone 11 pro landscape,Samsung S9+ landscape" --browsers=webkit,firefox,chromium --headless=False

python helpers/contexts/save_adminv2_context.py && pytest tests/adminv2 --workers 2
## Useful Links
https://playwright.dev/python