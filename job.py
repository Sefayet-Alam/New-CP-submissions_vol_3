# This request is best satisfied by the Python library for 'google_maps'.
# I already know API descriptions for all of them.
# I need to find the user's location. So I'll use the user location as the destination.
print(google_maps.navigate(
  destination=MY_LOCATION,
))