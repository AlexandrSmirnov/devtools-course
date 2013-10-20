#pragma once
enum Unit {Dollar, Euro, Ruble, Pound};
struct Currency
{
	Unit unit;
	double value;
};
class CurrencyConvert
{
public:
	CurrencyConvert(void);
	virtual ~CurrencyConvert(void);
	Currency ConvertCurrency(Currency currency, Unit UnitOutput);
};