# Trading P&L Technical Test

## Demo

A demo is available in the file test.py and the functions are in the file trading_helper.py

To run the GUI, please type 'streamlit run test.py' in your terminal.

## How does it work ?

The method used to compute the realized P&L is not a FIFO nor a LIFO approach but a 'Greedy' one. 
The order that will be chosen to close the position at time X is the one that maximize the profit (or minimize loss) among the live orders at time X.
Assume no transaction costs.

## Scalability

Works with larger csv file containing more trades and more than 3 securities.

## Technologies used

Python language and below libraries:
- calculation and data manipulation with pandas, numpy, intertools, and datetime
- data visualization with matplotlib and plotly
- GUI with streamlit
