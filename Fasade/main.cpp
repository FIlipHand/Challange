#include <iostream>

using namespace std;

/*       ▄              ▄    
        ▌▒█           ▄▀▒▌   
        ▌▒▒█        ▄▀▒▒▒▐   
       ▐▄█▒▒▀▀▀▀▄▄▄▀▒▒▒▒▒▐   
     ▄▄▀▒▒▒▒▒▒▒▒▒▒▒█▒▒▄█▒▐   
   ▄▀▒▒▒░░░▒▒▒░░░▒▒▒▀██▀▒▌   
  ▐▒▒▒▄▄▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▀▄▒▌  
  ▌░░▌█▀▒▒▒▒▒▄▀█▄▒▒▒▒▒▒▒█▒▐  
 ▐░░░▒▒▒▒▒▒▒▒▌██▀▒▒░░░▒▒▒▀▄▌ 
 ▌░▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░▒▒▒▒▌ 
▌▒▒▒▄██▄▒▒▒▒▒▒▒▒░░░░░░░░▒▒▒▐ 
▐▒▒▐▄█▄█▌▒▒▒▒▒▒▒▒▒▒░▒░▒░▒▒▒▒▌
▐▒▒▐▀▐▀▒▒▒▒▒▒▒▒▒▒▒▒▒░▒░▒░▒▒▐ 
 ▌▒▒▀▄▄▄▄▄▄▒▒▒▒▒▒▒▒░▒░▒░▒▒▒▌ 
 ▐▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░▒░▒▒▄▒▒▐  
  ▀▄▒▒▒▒▒▒▒▒▒▒▒▒▒░▒░▒▄▒▒▒▒▌  
    ▀▄▒▒▒▒▒▒▒▒▒▒▄▄▄▀▒▒▒▒▄▀   
      ▀▄▄▄▄▄▄▀▀▀▒▒▒▒▒▄▄▀     
         ▀▀▀▀▀▀▀▀▀▀▀▀
*/
class Wallet;
class Broker;
class UI;
class Account;

class Wallet
{
public:
    float doge_amount;
    string address;
    void send(float amount, string address);
};

class Account
{
public:
    Wallet *wallet;
    float usd_amount;
    Broker *broker;
    void transfer_money(float amount)
    {
        usd_amount = amount;
        cout << "Tranzakcja ukonczona pomyslnie\n";
    }
};

class Broker
{
public:
    float doge_usd_price;
    void process_transaction(Account *account, float amount)
    {
        if (amount > 0)
        {
            account->wallet->doge_amount = amount - 1;
            account->usd_amount -= (doge_usd_price * amount);
        }
        else
        {
            account->wallet->doge_amount = account->wallet->doge_amount + amount - 1;
            account->usd_amount += (doge_usd_price * (-1 * amount));
        }
    };
};

class UI
{
public:
    Account *user_account;
    void buy_dogecoin(float amount)
    {
        float usd_price = user_account->broker->doge_usd_price * amount;
        if (usd_price > user_account->usd_amount)
        {
            cout << "Brak wystarczajacych srodkuw na koncie\n";
        }
        else
        {
            user_account->broker->process_transaction(user_account, amount);
            cout << "Tranzakcja zakonczona pomyslnie\n";
        }
    }
    void sell_dogecoin(float amount)
    {
        if (amount > user_account->wallet->doge_amount)
        {
            cout << "Brak wystarczajacej ilosci pieskow\n";
        }
        else
        {
            user_account->broker->process_transaction(user_account, -1 * amount);
            cout << "Tranzakcja zakonczona pomyslnie\n";
        }
    }
    void buy_usd(float amount)
    {
        user_account->transfer_money(amount);
        cout << "Przelano " << amount << " dolarow na konto\n";
    }
};

int main()
{
    // Setup wszystkiego (tego user nie widzi)
    Broker coinbase;
    coinbase.doge_usd_price = 0.4243;
    Wallet user_wallet;
    user_wallet.doge_amount = 0;
    user_wallet.address = "cd1de81edba8dc667052d001414a8e249c24be5a5762301e46fb830ca6e8938b";
    Account user_account;
    user_account.wallet = &user_wallet;
    user_account.usd_amount = 0;
    user_account.broker = &coinbase;

    UI user_interface;
    user_interface.user_account = &user_account;

    // Tutaj user wchodzi w interakcje z systemem
    user_interface.buy_usd(100.0);
    user_interface.buy_dogecoin(1000);
    user_interface.buy_dogecoin(200);
    user_interface.sell_dogecoin(300);
    user_interface.sell_dogecoin(100);

    return 0;
}