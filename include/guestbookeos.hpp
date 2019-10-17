#include <eosiolib/eosio.hpp>
#include <eosiolib/time.hpp>
#include <eosiolib/system.hpp>
using namespace std;
using namespace eosio;

class [[eosio::contract]] guestbookeos : public eosio::contract {

  private:

    struct [[eosio::table]] user_info {
      uint64_t        id;
      name            username;
      string          text;
      time_point_sec  created_at;

      uint64_t primary_key() const { return id; }
    };

    typedef eosio::multi_index<name("users"), user_info> users_table;

    users_table _users;

  public:

    guestbookeos( name receiver, name code, datastream<const char*> ds ):contract(receiver, code, ds),_users(receiver, receiver.value) {}

    [[eosio::action]]
    void login(name username, string message);
};