/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:52:40 by dkaratae          #+#    #+#             */
/*   Updated: 2023/11/17 20:44:59 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main()
{
    std::cout << "-------=======STACK=======-------" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);

    // std::cout << "-------=======LIST=======-------" << std::endl;

    // std::list<int> lst;
    // lst.push_back(5);
    // lst.push_back(17);
    // std::cout << lst.back() << std::endl;
    // lst.pop_back();
    // std::cout << lst.size() << std::endl;
    // lst.push_back(3);
    // lst.push_back(5);
    // lst.push_back(737);
    // //[...]
    // lst.push_back(0);
    // std::list<int>::iterator it1 = lst.begin();
    // std::list<int>::iterator ite2 = lst.end();
    // ++it1;
    // --it1;
    // while (it1 != ite2)
    // {
    //     std::cout << *it1 << std::endl;
    //     ++it1;
    // }
    // // std::list<int> s1(lst);
    return 0;
}