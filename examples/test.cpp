#include <boost/statechart/state.hpp>
#include <boost/statechart/state_machine.hpp>
#include <boost/statechart/custom_reaction.hpp>
#include <boost/statechart/result.hpp>
#include <boost/mpl/list.hpp>
#include <iostream>
#include <ostream>

struct event
:
	public boost::statechart::event<
		::event
	>
{};

class state1;

class state2;

class machine
:
	public boost::statechart::state_machine<
		::machine,
		::state1
	>
{
};

class state1
:
	public boost::statechart::simple_state<
		::state1,
		::machine
	>
{
public:
	typedef boost::mpl::list<
		boost::statechart::custom_reaction<
			::event
		>
	> reactions;

	boost::statechart::result
	react(
		::event const &
	)
	{
		return transit<state2>(42);
	}
};

class state2
:
	public boost::statechart::state<
		::state2,
		::machine
	>
{
public:
	explicit state2(
		my_context _ctx,
		int const _foo
	)
	:
		my_base(
			_ctx
		)
	{
		std::cout << _foo << '\n';
	}
};

int main()
{
	::machine machine;

	machine.initiate();

	machine.process_event(
		::event()
	);
}
