# libmds
Library for misc. data structures

## Features:
- Written in pure C
- Has data structures:
    - vector
    - llist
    - string
- Allocates lots of stuff on heap, so is 2x slower than C++ STL :-(
- But is quite a lot more memory-efficient!

## Compiling
### Prerequisites:
- gcc/clang
- GNU make
- sphinx\*
- sphinx_rtd_theme/sphinx-rtd-theme\*
- doxygen\*

\* Required for documentation

To build static and dynamic libraries with documentation:
```linux
$ make
```
To build without documentation:
```linux
$ (cd src/; make)
```

# Warranty (or lack of it)
No warranties, either express or implied, are hereby given. All
software is supplied as is, without guarantee.  The user assumes all
responsibility for damages resulting from the use of these features,
including, but not limited to, frustration, disgust, system abends, disk
head-crashes, general malfeasance, floods, fires, shark attack, nerve
gas, locust infestation, cyclones, hurricanes, tsunamis, local
electromagnetic disruptions, hydraulic brake system failure, invasion,
hashing collisions, normal wear and tear of friction surfaces, comic
radiation, inadvertent destruction of sensitive electronic components,
windstorms, the Riders of Nazgul, infuriated chickens, malfunctioning
mechanical or electrical sexual devices, premature activation of the
distant early warning system, peasant uprisings, halitosis, artillery
bombardment, explosions, cave-ins, and/or frogs falling from the sky.

## Regarding the above disclaimer
This message does not reflect the thoughts or opinions of either myself, my company, my friends, or my family; don’t quote me on that; don’t quote me on anything; all rights reserved; you may distribute this message freely but you may not make a profit from it; terms are subject to change without notice; illustrations are slightly enlarged to show detail; any resemblance to actual persons, living, dead or otherwise, is unintentional and purely coincidental; do not remove this disclaimer under penalty of law; hand wash only, tumble dry on low heat; do not bend, fold, staple, mutilate, or spindle; your mileage may vary; no substitutions allowed; for a limited time only; this message is void where prohibited, taxed, or otherwise restricted; caveat emptor; message is provided “as is” without any warranties; reader assumes full responsibility; an equal opportunity message; not responsible for the loose nut in front of the keyboard; quantities are limited while supplies last; if any defects are discovered, do not attempt to read them yourself, but return to an authorized service center; read at your own risk; parental guidance is advised; keep away from sunlight; keep away from pets and small children; limit one-per-family please; no money down; no purchase necessary; you need not be present to win; some assembly required; batteries not included; instructions are included; action figures sold separately; no preservatives added; slippery when wet; safety goggles may be required during use; sealed for your protection, do not read if safety seal is broken; call before you dig; not liable for damages arising from use or misuse; for external use only; all prices are final, except the final price, which is subject to change without notice; if rash, irritation, redness, or swelling develops, discontinue reading; read only with proper ventilation; avoid extreme temperatures and store in a cool dry place; keep away from open flames; avoid contact with eyes and skin and avoid inhaling fumes; do not puncture, incinerate, or store above 120 degrees Fahrenheit; do not place near a flammable or magnetic source; smoking this message could be hazardous to your health; no salt, MSG, artificial color, flavoring, or text added; if ingested, do not induce vomiting, and if symptoms persist, consult a doctor; possible penalties for early withdrawal; offer valid only at participating sites; do not attempt to drive a vehicle or operate heavy machinery while reading this message; allow 28 days for delivery; must be 18 to read; this is a trained professional, do not try this at home; not responsible for damage or injury due to misuse, accident, lightning, flood, tornado, tsunami, volcanic eruption, earthquake, hurricanes and other Acts of God, neglect, damage from incorrect line voltage, improper or unauthorized reading, broken antenna or marred cabinet, missing or altered serial numbers, electromagnetic radiation from nuclear blasts, sonic boom vibrations, customer adjustments that are not covered in this list, and incidents owing to an airplane crash, ship sinking or taking on water, motor vehicle crashing, dropping the item, falling rocks, leaky roof, broken glass, mud slides, forest fire, leafs on the line or projectile (which can include, but not be limited to, arrows, bullets, shot, BB’s, shrapnel, lasers, napalm, torpedoes, or emissions of X-rays, a, b and g rays, meteorites, knives, stones, cats or other small fur bearing mammals, etc.); other restrictions apply.
