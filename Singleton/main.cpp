#include <iostream>
#include <fstream>

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

class Logger
{
public:
    Logger(const Logger &) = delete;
    void save_msg(string message)
    {
        file << message;
    }
    static Logger &get()
    {
        return log_instance;
    };

private:
    ofstream file;
    Logger()
    {
        file.open("logs.txt");
    }
    static Logger log_instance;
    ~Logger()
    {
        file.close();
    }
};

Logger Logger::log_instance;

class Broker
{
public:
    float doge_price;
    void buy_doge(float amount)
    {
        Logger::get().save_msg("User bought ");
        Logger::get().save_msg(to_string(amount));
        Logger::get().save_msg(" DOGE at ");
        Logger::get().save_msg(to_string(doge_price));
        Logger::get().save_msg("\n");
    }
    void sell_doge(float amount)
    {
        Logger::get().save_msg("User sold ");
        Logger::get().save_msg(to_string(amount));
        Logger::get().save_msg(" DOGE at ");
        Logger::get().save_msg(to_string(doge_price));
        Logger::get().save_msg("\n");
    }
};

int main()
{
    Broker coinbase;
    coinbase.doge_price = 0.5278;
    coinbase.buy_doge(100);
    coinbase.doge_price = 0.5688;
    coinbase.buy_doge(100);
    coinbase.doge_price = 0.6021;
    coinbase.sell_doge(50);

    return 0;
}
