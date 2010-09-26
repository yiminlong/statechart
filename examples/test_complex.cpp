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

class state3;

class state4;

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
		return transit<state4>(42);
	}
};

class state2
:
	public boost::statechart::state<
		::state2,
		::machine,
		::state3
	>
{
public:
	explicit state2(
		my_context _ctx
	)
	:
		my_base(
			_ctx
		)
	{
	}
};

class state3
:
	public boost::statechart::state<
		::state3,
		::state2
	>
{
public:
	explicit state3(
		my_context _ctx
	)
	:
		my_base(
			_ctx
		)
	{}
};

class state4
:
	public boost::statechart::state<
		::state4,
		::state2
	>
{
public:
	explicit state4(
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
