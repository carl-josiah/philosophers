#!/bin/bash

echo "=== CORRECTED PHILOSOPHERS PARSING TEST ==="
echo "Compiling..."
make clean && make

if [ ! -f "./philo" ]; then
    echo "❌ COMPILATION FAILED!"
    exit 1
fi

echo ""

# Counters
TOTAL=0
PASSED=0
FAILED=0

# Function to test cases
test_case() {
    local description="$1"
    local expected="$2"  # "PASS" or "FAIL"
    shift 2
    local args=("$@")
    
    TOTAL=$((TOTAL + 1))
    printf "Test %2d: %-40s " "$TOTAL" "$description"
    
    # Run the command and capture both output and exit code
    output=$(./philo "${args[@]}" 2>&1 &)
    pid=$!
    sleep 0.2  # Give it time to start or fail
    
    # Check if process is still running or completed
    if kill -0 $pid 2>/dev/null; then
        kill $pid 2>/dev/null
        wait $pid 2>/dev/null
        success=true
    else
        wait $pid 2>/dev/null
        exit_code=$?
        if [[ $exit_code -eq 0 ]] && [[ ! "$output" =~ "ERROR" ]] && [[ ! "$output" =~ "Usage:" ]]; then
            success=true
        else
            success=false
        fi
    fi
    
    # Check if it behaves as expected
    if [[ "$expected" == "PASS" ]]; then
        if [[ "$success" == true ]]; then
            echo "✅ CORRECT"
            PASSED=$((PASSED + 1))
        else
            echo "❌ WRONG (should pass)"
            echo "     Got: $output"
            FAILED=$((FAILED + 1))
        fi
    else  # expected == "FAIL"
        if [[ "$success" == false ]]; then
            echo "✅ CORRECT"
            PASSED=$((PASSED + 1))
        else
            echo "❌ WRONG (should fail)"
            echo "     Expected failure but program started"
            FAILED=$((FAILED + 1))
        fi
    fi
}

echo "=== ARGUMENT COUNT VALIDATION ==="
test_case "No arguments" "FAIL"
test_case "1 argument" "FAIL" 5
test_case "2 arguments" "FAIL" 5 400
test_case "3 arguments" "FAIL" 5 400 200
test_case "4 arguments (VALID)" "PASS" 5 400 200 200
test_case "5 arguments (VALID)" "PASS" 5 400 200 200 10
test_case "6 arguments" "FAIL" 5 400 200 200 10 100

echo ""
echo "=== BASIC VALIDATION ==="
test_case "Simple valid case" "PASS" 1 1 1 1
test_case "With meal count" "PASS" 1 1 1 1 1
test_case "Realistic case" "PASS" 5 800 200 200
test_case "With plus signs" "PASS" +5 +400 +200 +200
test_case "Leading spaces" "PASS" "  5" 400 200 200
test_case "Trailing spaces" "PASS" "5  " 400 200 200

echo ""
echo "=== INVALID CASES ==="
test_case "Zero philosophers" "FAIL" 0 400 200 200
test_case "Negative number" "FAIL" -5 400 200 200
test_case "Letters" "FAIL" abc 400 200 200
test_case "Empty string" "FAIL" "" 400 200 200
test_case "Only spaces" "FAIL" "   " 400 200 200

echo ""
echo "=== FINAL RESULTS ==="
echo "Total tests: $TOTAL"
echo "Correct: $PASSED"
echo "Wrong: $FAILED"
echo "Accuracy: $(( PASSED * 100 / TOTAL ))%"

if [ $FAILED -eq 0 ]; then
    echo ""
    echo "🎉 PERFECT! Your parsing is 100% CORRECT! 🎉"
    echo "🔥 You handle all edge cases perfectly! 🔥"
    exit 0
else
    echo ""
    echo "⚠️  Your parsing failed $FAILED out of $TOTAL tests."
    exit 1
fi