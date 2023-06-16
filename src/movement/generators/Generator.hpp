#pragma once

#include <ostream>
#include "../../Vector2.hpp"

/**
 * Abstract class responsible for generating possible Pawn movements.
 *
 * Positions are generated not all at once and returned, but in sequence.
 * The generator can generate the next position until it has reached the end.
 * Once the generator has ended, it must be restarted to work properly the next time.
 */
class Generator {
private:
    bool end = false;

public:
    virtual ~Generator() = default;

    /**
     * Checks if the generator has reached the end.
     *
     * @return True if the generator has ended, False otherwise.
     */
    virtual bool hasEnded() { return end; };

    /**
     * Gets the next move position in the sequence.
     *
     * @return The next move position as a Vector2 object.
     */
    virtual Vector2 getNextMovePosition() = 0;

    /**
     * Skips to the next generator.
     *
     * @return True if successful, False otherwise.
     */
    virtual bool skipToNextGenerator() = 0;

    /**
     * Sets the generator to its ended state.
     */
    void setEnded() { end = true; }

    /**
     * Sets the generator to its not ended state.
     */
    void setNotEnded() { end = false; }

    /**
     * Resets the generator to its initial state.
     */
    virtual void reset() {
        end = false;
    }

    virtual void print(std::ostream& os) const = 0;

    friend std::ostream &operator<<(std::ostream &os, const Generator &generator) {
        generator.print(os);
        return os;
    }
};
