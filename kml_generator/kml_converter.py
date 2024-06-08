import folium
import pandas as pd

# Load the GPS data from a CSV file
data = pd.read_csv('GPS_DATA.CSV')

# Create a map centered at the first coordinate
map_center = [data['latitude'].iloc[0], data['longitude'].iloc[0]]
mymap = folium.Map(location=map_center, zoom_start=15)

# Add points to the map
for i in range(len(data)):
    lat = data['latitude'].iloc[i]
    lon = data['longitude'].iloc[i]
    timestamp = data['timestamp'].iloc[i]
    altitude = data['altitude'].iloc[i]
    folium.Marker(
        location=[lat, lon],
        popup=f"Time: {timestamp}\nAltitude: {altitude}m",
        icon=folium.Icon(color='blue', icon='info-sign')
    ).add_to(mymap)

# Save the map to an HTML file
mymap.save('gps_route_map.html')
