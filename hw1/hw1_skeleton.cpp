
#include <chrono>
#include <unistd.h>
#include <iostream>
using namespace std;

unsigned long get_current_time_in_secs()
{
  auto now = chrono::steady_clock::now();
  auto now_ms = std::chrono::time_point_cast<std::chrono::seconds>(now);
  auto epoch = now_ms.time_since_epoch();
  auto value = std::chrono::duration_cast<std::chrono::seconds>(epoch);
  unsigned long duration = value.count();
  return duration;
}

class Dispatcher
{
public:
  Dispatcher (unsigned int n, unsigned int t);
  void dispatch_requests(unsigned long delay,  unsigned int request_count);
private:
  bool enable_request(); /* implement */
private:
  unsigned int numberOfRequests;
  unsigned int time_interval;
  unsigned int active_requests;
  unsigned long end_time;
};

Dispatcher::Dispatcher(unsigned int n, unsigned int t)
{
  numberOfRequests = n;
  time_interval = t;
  active_requests = 0;
  end_time = get_current_time_in_secs() + time_interval;
}

void
Dispatcher::dispatch_requests(unsigned long delay, unsigned int request_count)
{
  sleep(delay);
  for (unsigned int k=0; k<request_count; k++)
    {
    if (enable_request() == true)
      cout << "Request " << k<< " is being processed" << endl;
    else
      cout << "Request " << k<< " has been rejected" << endl;
    }
}

bool Dispatcher::enable_request() {
  unsigned long current_time = get_current_time_in_secs();
  if (current_time > end_time) {
    active_requests = 0;
    end_time = current_time + time_interval;
  }
  if (active_requests < numberOfRequests) {
    active_requests++;
    return true;
  }
  return false;
} 


void scenario1()
{
  // Process one request per second
  Dispatcher dispatcher(1,1);
  cout << "scenario1 first dispatch" << endl;
  dispatcher.dispatch_requests(0, 1);
  cout << "scenario1 second dispatch" << endl;
  dispatcher.dispatch_requests(1, 2); //dispatch 2 requests after waiting 1 sec;
}

void scenario2()
{
  // Process up to 4 request every two second
  Dispatcher dispatcher(4,2);
  cout <<"scenario2 first dispatch" << endl;
  dispatcher.dispatch_requests(0, 1);
  cout << "scenario2 second dispatch" << endl;
  dispatcher.dispatch_requests(1, 4); //dispatch 4 requests after waiting 1 sec;
  cout << "scenario2 third dispatch" << endl;
  dispatcher.dispatch_requests(2, 4); //dispatch 4 requests after waiting 2 sec;
  cout << "scenario2 fourth dispatch" << endl;
  dispatcher.dispatch_requests(2, 5); //dispatch 5 requests after waiting 2 sec;
}

int main(int argc, char** argv)
{
  cout << "Running scenario 1" << endl;
  scenario1();
  cout << "Running scenario 2" << endl;
  scenario2();
  return 0;
}
