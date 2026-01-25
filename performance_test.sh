#!/bin/bash

GREEN='\033[0;32m'
YELLOW='\033[1;33m'
RED='\033[0;31m'
BLUE='\033[0;34m'
NC='\033[0m'

echo -e "${BLUE}╔════════════════════════════════════════════╗${NC}"
echo -e "${BLUE}║     Push_swap Performance Test            ║${NC}"
echo -e "${BLUE}╔════════════════════════════════════════════╗${NC}\n"

# Test 1: 3 sayı (max 3 operasyon)
echo -e "${YELLOW}📊 Test 1: 3 sayı (max 3 operasyon)${NC}"
total=0
max=0
min=999999
for i in {1..100}; do
    ARG=$(shuf -i 1-100 -n 3 | tr '\n' ' ')
    OPS=$(./push_swap $ARG | wc -l)
    total=$((total + OPS))
    [ $OPS -gt $max ] && max=$OPS
    [ $OPS -lt $min ] && min=$OPS
done
avg=$((total / 100))
if [ $max -le 3 ]; then
    echo -e "${GREEN}✓ BAŞARILI${NC} - Max: $max, Min: $min, Avg: $avg"
else
    echo -e "${RED}✗ BAŞARISIZ${NC} - Max: $max (>3), Min: $min, Avg: $avg"
fi
echo ""

# Test 2: 5 sayı (max 12 operasyon)
echo -e "${YELLOW}📊 Test 2: 5 sayı (max 12 operasyon)${NC}"
total=0
max=0
min=999999
for i in {1..100}; do
    ARG=$(shuf -i 1-100 -n 5 | tr '\n' ' ')
    OPS=$(./push_swap $ARG | wc -l)
    total=$((total + OPS))
    [ $OPS -gt $max ] && max=$OPS
    [ $OPS -lt $min ] && min=$OPS
done
avg=$((total / 100))
if [ $max -le 12 ]; then
    echo -e "${GREEN}✓ BAŞARILI${NC} - Max: $max, Min: $min, Avg: $avg"
else
    echo -e "${RED}✗ BAŞARISIZ${NC} - Max: $max (>12), Min: $min, Avg: $avg"
fi
echo ""

# Test 3: 100 sayı
echo -e "${YELLOW}📊 Test 3: 100 sayı${NC}"
echo "Notlandırma: <700 (5p), <900 (4p), <1100 (3p), <1300 (2p), <1500 (1p)"
total=0
max=0
min=999999
for i in {1..20}; do
    ARG=$(shuf -i 1-500 -n 100 | tr '\n' ' ')
    OPS=$(./push_swap $ARG | wc -l)
    total=$((total + OPS))
    [ $OPS -gt $max ] && max=$OPS
    [ $OPS -lt $min ] && min=$OPS
done
avg=$((total / 20))

if [ $avg -lt 700 ]; then
    echo -e "${GREEN}✓ MÜKEMMEL (5/5)${NC} - Max: $max, Min: $min, Avg: $avg"
elif [ $avg -lt 900 ]; then
    echo -e "${GREEN}✓ ÇOK İYİ (4/5)${NC} - Max: $max, Min: $min, Avg: $avg"
elif [ $avg -lt 1100 ]; then
    echo -e "${YELLOW}○ İYİ (3/5)${NC} - Max: $max, Min: $min, Avg: $avg"
elif [ $avg -lt 1300 ]; then
    echo -e "${YELLOW}○ ORTA (2/5)${NC} - Max: $max, Min: $min, Avg: $avg"
elif [ $avg -lt 1500 ]; then
    echo -e "${RED}△ DÜŞÜK (1/5)${NC} - Max: $max, Min: $min, Avg: $avg"
else
    echo -e "${RED}✗ YETERSİZ (0/5)${NC} - Max: $max, Min: $min, Avg: $avg"
fi
echo ""

# Test 4: 500 sayı
echo -e "${YELLOW}📊 Test 4: 500 sayı${NC}"
echo "Notlandırma: <5500 (5p), <7000 (4p), <8500 (3p), <10000 (2p), <11500 (1p)"
total=0
max=0
min=999999
for i in {1..10}; do
    ARG=$(shuf -i 1-1000 -n 500 | tr '\n' ' ')
    OPS=$(./push_swap $ARG | wc -l)
    total=$((total + OPS))
    [ $OPS -gt $max ] && max=$OPS
    [ $OPS -lt $min ] && min=$OPS
done
avg=$((total / 10))

if [ $avg -lt 5500 ]; then
    echo -e "${GREEN}✓ MÜKEMMEL (5/5)${NC} - Max: $max, Min: $min, Avg: $avg"
elif [ $avg -lt 7000 ]; then
    echo -e "${GREEN}✓ ÇOK İYİ (4/5)${NC} - Max: $max, Min: $min, Avg: $avg"
elif [ $avg -lt 8500 ]; then
    echo -e "${YELLOW}○ İYİ (3/5)${NC} - Max: $max, Min: $min, Avg: $avg"
elif [ $avg -lt 10000 ]; then
    echo -e "${YELLOW}○ ORTA (2/5)${NC} - Max: $max, Min: $min, Avg: $avg"
elif [ $avg -lt 11500 ]; then
    echo -e "${RED}△ DÜŞÜK (1/5)${NC} - Max: $max, Min: $min, Avg: $avg"
else
    echo -e "${RED}✗ YETERSİZ (0/5)${NC} - Max: $max, Min: $min, Avg: $avg"
fi
echo ""

echo -e "${BLUE}╚════════════════════════════════════════════╝${NC}"
