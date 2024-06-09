import folium
import pandas as pd

# Load the GPS data from a CSV file
data = pd.read_csv('csv_data/GPSDATA.CSV')

# Create a map centered at the first coordinate
map_center = [data['latitude'].iloc[0], data['longitude'].iloc[0]]
mymap = folium.Map(location=map_center, zoom_start=15)

# Add points to the map
for i in range(len(data)):
    lat = data['latitude'].iloc[i]
    lon = data['longitude'].iloc[i]
    timestamp = data['timestamp'].iloc[i]
    folium.Marker(
        location=[lat, lon],
        popup=f"Time: {timestamp}m",
        icon=folium.Icon(color='darkpurple', icon='info-sign')
    ).add_to(mymap)

# Save the map to an HTML file
mymap.save('gps_route_map.html')
