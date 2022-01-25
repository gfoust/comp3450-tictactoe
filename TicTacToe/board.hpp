#pragma once
#include <array>
#include <optional>
#include <vector>

namespace tic {

    struct Location {
        int row, col;
    };

    enum class Player { Player1, Player2 };

    using OptPlayer = std::optional<Player>;
    using Row = std::array<OptPlayer, 3>;
    
    class Board {
    public:
        Board();
        OptPlayer getCell(Location loc);
        void setCell(Location loc, Player player);
        bool isFull();
        OptPlayer winner();

    private:
        std::vector<Row> cells;

        OptPlayer same(Location a, Location b, Location c);
    };

}