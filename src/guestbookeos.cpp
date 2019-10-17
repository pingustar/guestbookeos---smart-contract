#include <guestbookeos.hpp>

void guestbookeos::login(name username, string message) {
  // Ensure this action is authorized by the player
  require_auth(username);

  const uint64_t id = _users.available_primary_key();
  
  _users.emplace(username,  [&](auto& new_user) {
      new_user.id = id;
      new_user.username = username;
      new_user.text = message;
      new_user.created_at = time_point_sec(now());
    });
}

EOSIO_DISPATCH(guestbookeos, (login))