#include <iostream>

using namespace std;

/*
         ▄              ▄    
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

class Cryptocurrency
{
public:
    float price;
    bool daddy_elon_love;
};

class Bitcoin : public Cryptocurrency
{
};

class Dogecoin : public Cryptocurrency
{
};

class Mine
{
public:
    virtual float mine_crypto(Cryptocurrency *crypto)
    {
        return 0;
    }
};

class CPU_Mine : public Mine
{
    float mine_crypto(Cryptocurrency *crypto)
    {
        cout << "Mined: " << 0.001 * crypto->price << " on CPU\n";
        return 0.001 * crypto->price;
    }
};
class GPU_Mine : public Mine
{
    float mine_crypto(Cryptocurrency *crypto)
    {
        cout << "Mined: " << 0.01 * crypto->price << " on GPU\n";
        return 0.01 * crypto->price;
    }
};

class Computer
{
public:
    float money_amount;
    void mine_and_change(Mine *mining, Cryptocurrency *crypto)
    {
        money_amount += (mining->mine_crypto(crypto) * 3.87);
        cout << "You now have: " << money_amount << " USD\n";
    }
};

int main()
{
    Cryptocurrency doge = Dogecoin();
    doge.price = 0.51443;
    doge.daddy_elon_love = true;
    Cryptocurrency bitcoin = Bitcoin();
    bitcoin.price = 48523.39;
    bitcoin.daddy_elon_love = false;

    Computer computer;
    computer.money_amount = 0;

    GPU_Mine gpumine = GPU_Mine();
    CPU_Mine cpumine = CPU_Mine();

    computer.mine_and_change(&cpumine, &doge);
    computer.mine_and_change(&gpumine, &bitcoin);

    return 0;
}