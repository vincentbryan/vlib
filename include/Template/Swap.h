//
// Created by vincent on 18-3-31.
//

#pragma once

namespace vlib{
    template <typename T>
    void swap(T& a, T& b){
        T temp(move(a));
        a = move(b);
        b = move(temp);
    }
}

