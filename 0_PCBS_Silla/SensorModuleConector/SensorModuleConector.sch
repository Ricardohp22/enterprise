<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="7.6.0">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="2" name="Route2" color="1" fill="3" visible="no" active="no"/>
<layer number="3" name="Route3" color="4" fill="3" visible="no" active="no"/>
<layer number="4" name="Route4" color="1" fill="4" visible="no" active="no"/>
<layer number="5" name="Route5" color="4" fill="4" visible="no" active="no"/>
<layer number="6" name="Route6" color="1" fill="8" visible="no" active="no"/>
<layer number="7" name="Route7" color="4" fill="8" visible="no" active="no"/>
<layer number="8" name="Route8" color="1" fill="2" visible="no" active="no"/>
<layer number="9" name="Route9" color="4" fill="2" visible="no" active="no"/>
<layer number="10" name="Route10" color="1" fill="7" visible="no" active="no"/>
<layer number="11" name="Route11" color="4" fill="7" visible="no" active="no"/>
<layer number="12" name="Route12" color="1" fill="5" visible="no" active="no"/>
<layer number="13" name="Route13" color="4" fill="5" visible="no" active="no"/>
<layer number="14" name="Route14" color="1" fill="6" visible="no" active="no"/>
<layer number="15" name="Route15" color="4" fill="6" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="15" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="6" fill="9" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
<layer number="99" name="SpiceOrder" color="5" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="pinhead">
<description>&lt;b&gt;Pin Header Connectors&lt;/b&gt;&lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="2X07">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<wire x1="-8.89" y1="-1.905" x2="-8.255" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-6.985" y1="-2.54" x2="-6.35" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-6.35" y1="-1.905" x2="-5.715" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-4.445" y1="-2.54" x2="-3.81" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-3.81" y1="-1.905" x2="-3.175" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="-2.54" x2="-1.27" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="-1.905" x2="-0.635" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="0.635" y1="-2.54" x2="1.27" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="1.27" y1="-1.905" x2="1.905" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="3.175" y1="-2.54" x2="3.81" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="3.81" y1="-1.905" x2="4.445" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="5.715" y1="-2.54" x2="6.35" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-8.89" y1="-1.905" x2="-8.89" y2="1.905" width="0.1524" layer="21"/>
<wire x1="-8.89" y1="1.905" x2="-8.255" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-8.255" y1="2.54" x2="-6.985" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-6.985" y1="2.54" x2="-6.35" y2="1.905" width="0.1524" layer="21"/>
<wire x1="-6.35" y1="1.905" x2="-5.715" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-5.715" y1="2.54" x2="-4.445" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-4.445" y1="2.54" x2="-3.81" y2="1.905" width="0.1524" layer="21"/>
<wire x1="-3.81" y1="1.905" x2="-3.175" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-3.175" y1="2.54" x2="-1.905" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="2.54" x2="-1.27" y2="1.905" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="1.905" x2="-0.635" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="2.54" x2="0.635" y2="2.54" width="0.1524" layer="21"/>
<wire x1="0.635" y1="2.54" x2="1.27" y2="1.905" width="0.1524" layer="21"/>
<wire x1="1.27" y1="1.905" x2="1.905" y2="2.54" width="0.1524" layer="21"/>
<wire x1="1.905" y1="2.54" x2="3.175" y2="2.54" width="0.1524" layer="21"/>
<wire x1="3.175" y1="2.54" x2="3.81" y2="1.905" width="0.1524" layer="21"/>
<wire x1="3.81" y1="1.905" x2="4.445" y2="2.54" width="0.1524" layer="21"/>
<wire x1="4.445" y1="2.54" x2="5.715" y2="2.54" width="0.1524" layer="21"/>
<wire x1="5.715" y1="2.54" x2="6.35" y2="1.905" width="0.1524" layer="21"/>
<wire x1="-6.35" y1="1.905" x2="-6.35" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-3.81" y1="1.905" x2="-3.81" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="1.905" x2="-1.27" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="1.27" y1="1.905" x2="1.27" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="3.81" y1="1.905" x2="3.81" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="6.35" y1="1.905" x2="6.35" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="4.445" y1="-2.54" x2="5.715" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="1.905" y1="-2.54" x2="3.175" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="-2.54" x2="0.635" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-3.175" y1="-2.54" x2="-1.905" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-5.715" y1="-2.54" x2="-4.445" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-8.255" y1="-2.54" x2="-6.985" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="6.35" y1="-1.905" x2="6.985" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="8.255" y1="-2.54" x2="8.89" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="6.35" y1="1.905" x2="6.985" y2="2.54" width="0.1524" layer="21"/>
<wire x1="6.985" y1="2.54" x2="8.255" y2="2.54" width="0.1524" layer="21"/>
<wire x1="8.255" y1="2.54" x2="8.89" y2="1.905" width="0.1524" layer="21"/>
<wire x1="8.89" y1="1.905" x2="8.89" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="6.985" y1="-2.54" x2="8.255" y2="-2.54" width="0.1524" layer="21"/>
<pad name="1" x="-7.62" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="2" x="-7.62" y="1.27" drill="1.016" shape="octagon"/>
<pad name="3" x="-5.08" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="4" x="-5.08" y="1.27" drill="1.016" shape="octagon"/>
<pad name="5" x="-2.54" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="6" x="-2.54" y="1.27" drill="1.016" shape="octagon"/>
<pad name="7" x="0" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="8" x="0" y="1.27" drill="1.016" shape="octagon"/>
<pad name="9" x="2.54" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="10" x="2.54" y="1.27" drill="1.016" shape="octagon"/>
<pad name="11" x="5.08" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="12" x="5.08" y="1.27" drill="1.016" shape="octagon"/>
<pad name="13" x="7.62" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="14" x="7.62" y="1.27" drill="1.016" shape="octagon"/>
<text x="-8.89" y="3.175" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-8.89" y="-4.445" size="1.27" layer="27">&gt;VALUE</text>
<rectangle x1="-7.874" y1="-1.524" x2="-7.366" y2="-1.016" layer="51"/>
<rectangle x1="-7.874" y1="1.016" x2="-7.366" y2="1.524" layer="51"/>
<rectangle x1="-5.334" y1="1.016" x2="-4.826" y2="1.524" layer="51"/>
<rectangle x1="-5.334" y1="-1.524" x2="-4.826" y2="-1.016" layer="51"/>
<rectangle x1="-2.794" y1="1.016" x2="-2.286" y2="1.524" layer="51"/>
<rectangle x1="-2.794" y1="-1.524" x2="-2.286" y2="-1.016" layer="51"/>
<rectangle x1="-0.254" y1="1.016" x2="0.254" y2="1.524" layer="51"/>
<rectangle x1="2.286" y1="1.016" x2="2.794" y2="1.524" layer="51"/>
<rectangle x1="4.826" y1="1.016" x2="5.334" y2="1.524" layer="51"/>
<rectangle x1="-0.254" y1="-1.524" x2="0.254" y2="-1.016" layer="51"/>
<rectangle x1="2.286" y1="-1.524" x2="2.794" y2="-1.016" layer="51"/>
<rectangle x1="4.826" y1="-1.524" x2="5.334" y2="-1.016" layer="51"/>
<rectangle x1="7.366" y1="1.016" x2="7.874" y2="1.524" layer="51"/>
<rectangle x1="7.366" y1="-1.524" x2="7.874" y2="-1.016" layer="51"/>
</package>
<package name="2X07/90">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<wire x1="-8.89" y1="-1.905" x2="-6.35" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-6.35" y1="-1.905" x2="-6.35" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-6.35" y1="0.635" x2="-8.89" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-8.89" y1="0.635" x2="-8.89" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-7.62" y1="6.985" x2="-7.62" y2="1.27" width="0.762" layer="21"/>
<wire x1="-6.35" y1="-1.905" x2="-3.81" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-3.81" y1="-1.905" x2="-3.81" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-3.81" y1="0.635" x2="-6.35" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="6.985" x2="-5.08" y2="1.27" width="0.762" layer="21"/>
<wire x1="-3.81" y1="-1.905" x2="-1.27" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="-1.905" x2="-1.27" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="0.635" x2="-3.81" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="6.985" x2="-2.54" y2="1.27" width="0.762" layer="21"/>
<wire x1="-1.27" y1="-1.905" x2="1.27" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="1.27" y1="-1.905" x2="1.27" y2="0.635" width="0.1524" layer="21"/>
<wire x1="1.27" y1="0.635" x2="-1.27" y2="0.635" width="0.1524" layer="21"/>
<wire x1="0" y1="6.985" x2="0" y2="1.27" width="0.762" layer="21"/>
<wire x1="1.27" y1="-1.905" x2="3.81" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="3.81" y1="-1.905" x2="3.81" y2="0.635" width="0.1524" layer="21"/>
<wire x1="3.81" y1="0.635" x2="1.27" y2="0.635" width="0.1524" layer="21"/>
<wire x1="2.54" y1="6.985" x2="2.54" y2="1.27" width="0.762" layer="21"/>
<wire x1="3.81" y1="-1.905" x2="6.35" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="6.35" y1="-1.905" x2="6.35" y2="0.635" width="0.1524" layer="21"/>
<wire x1="6.35" y1="0.635" x2="3.81" y2="0.635" width="0.1524" layer="21"/>
<wire x1="5.08" y1="6.985" x2="5.08" y2="1.27" width="0.762" layer="21"/>
<wire x1="6.35" y1="-1.905" x2="8.89" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="8.89" y1="-1.905" x2="8.89" y2="0.635" width="0.1524" layer="21"/>
<wire x1="8.89" y1="0.635" x2="6.35" y2="0.635" width="0.1524" layer="21"/>
<wire x1="7.62" y1="6.985" x2="7.62" y2="1.27" width="0.762" layer="21"/>
<pad name="2" x="-7.62" y="-3.81" drill="1.016" shape="octagon"/>
<pad name="4" x="-5.08" y="-3.81" drill="1.016" shape="octagon"/>
<pad name="6" x="-2.54" y="-3.81" drill="1.016" shape="octagon"/>
<pad name="8" x="0" y="-3.81" drill="1.016" shape="octagon"/>
<pad name="10" x="2.54" y="-3.81" drill="1.016" shape="octagon"/>
<pad name="12" x="5.08" y="-3.81" drill="1.016" shape="octagon"/>
<pad name="14" x="7.62" y="-3.81" drill="1.016" shape="octagon"/>
<pad name="1" x="-7.62" y="-6.35" drill="1.016" shape="octagon"/>
<pad name="3" x="-5.08" y="-6.35" drill="1.016" shape="octagon"/>
<pad name="5" x="-2.54" y="-6.35" drill="1.016" shape="octagon"/>
<pad name="7" x="0" y="-6.35" drill="1.016" shape="octagon"/>
<pad name="9" x="2.54" y="-6.35" drill="1.016" shape="octagon"/>
<pad name="11" x="5.08" y="-6.35" drill="1.016" shape="octagon"/>
<pad name="13" x="7.62" y="-6.35" drill="1.016" shape="octagon"/>
<text x="-9.525" y="-3.81" size="1.27" layer="25" ratio="10" rot="R90">&gt;NAME</text>
<text x="10.795" y="-3.81" size="1.27" layer="27" rot="R90">&gt;VALUE</text>
<rectangle x1="-8.001" y1="0.635" x2="-7.239" y2="1.143" layer="21"/>
<rectangle x1="-5.461" y1="0.635" x2="-4.699" y2="1.143" layer="21"/>
<rectangle x1="-2.921" y1="0.635" x2="-2.159" y2="1.143" layer="21"/>
<rectangle x1="-0.381" y1="0.635" x2="0.381" y2="1.143" layer="21"/>
<rectangle x1="2.159" y1="0.635" x2="2.921" y2="1.143" layer="21"/>
<rectangle x1="4.699" y1="0.635" x2="5.461" y2="1.143" layer="21"/>
<rectangle x1="7.239" y1="0.635" x2="8.001" y2="1.143" layer="21"/>
<rectangle x1="-8.001" y1="-2.921" x2="-7.239" y2="-1.905" layer="21"/>
<rectangle x1="-5.461" y1="-2.921" x2="-4.699" y2="-1.905" layer="21"/>
<rectangle x1="-8.001" y1="-5.461" x2="-7.239" y2="-4.699" layer="21"/>
<rectangle x1="-8.001" y1="-4.699" x2="-7.239" y2="-2.921" layer="51"/>
<rectangle x1="-5.461" y1="-4.699" x2="-4.699" y2="-2.921" layer="51"/>
<rectangle x1="-5.461" y1="-5.461" x2="-4.699" y2="-4.699" layer="21"/>
<rectangle x1="-2.921" y1="-2.921" x2="-2.159" y2="-1.905" layer="21"/>
<rectangle x1="-0.381" y1="-2.921" x2="0.381" y2="-1.905" layer="21"/>
<rectangle x1="-2.921" y1="-5.461" x2="-2.159" y2="-4.699" layer="21"/>
<rectangle x1="-2.921" y1="-4.699" x2="-2.159" y2="-2.921" layer="51"/>
<rectangle x1="-0.381" y1="-4.699" x2="0.381" y2="-2.921" layer="51"/>
<rectangle x1="-0.381" y1="-5.461" x2="0.381" y2="-4.699" layer="21"/>
<rectangle x1="2.159" y1="-2.921" x2="2.921" y2="-1.905" layer="21"/>
<rectangle x1="4.699" y1="-2.921" x2="5.461" y2="-1.905" layer="21"/>
<rectangle x1="2.159" y1="-5.461" x2="2.921" y2="-4.699" layer="21"/>
<rectangle x1="2.159" y1="-4.699" x2="2.921" y2="-2.921" layer="51"/>
<rectangle x1="4.699" y1="-4.699" x2="5.461" y2="-2.921" layer="51"/>
<rectangle x1="4.699" y1="-5.461" x2="5.461" y2="-4.699" layer="21"/>
<rectangle x1="7.239" y1="-2.921" x2="8.001" y2="-1.905" layer="21"/>
<rectangle x1="7.239" y1="-5.461" x2="8.001" y2="-4.699" layer="21"/>
<rectangle x1="7.239" y1="-4.699" x2="8.001" y2="-2.921" layer="51"/>
</package>
</packages>
<symbols>
<symbol name="PINH2X7">
<wire x1="-6.35" y1="-10.16" x2="8.89" y2="-10.16" width="0.4064" layer="94"/>
<wire x1="8.89" y1="-10.16" x2="8.89" y2="10.16" width="0.4064" layer="94"/>
<wire x1="8.89" y1="10.16" x2="-6.35" y2="10.16" width="0.4064" layer="94"/>
<wire x1="-6.35" y1="10.16" x2="-6.35" y2="-10.16" width="0.4064" layer="94"/>
<text x="-6.35" y="10.795" size="1.778" layer="95">&gt;NAME</text>
<text x="-6.35" y="-12.7" size="1.778" layer="96">&gt;VALUE</text>
<pin name="1" x="-2.54" y="7.62" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="2" x="5.08" y="7.62" visible="pad" length="short" direction="pas" function="dot" rot="R180"/>
<pin name="3" x="-2.54" y="5.08" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="4" x="5.08" y="5.08" visible="pad" length="short" direction="pas" function="dot" rot="R180"/>
<pin name="5" x="-2.54" y="2.54" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="6" x="5.08" y="2.54" visible="pad" length="short" direction="pas" function="dot" rot="R180"/>
<pin name="7" x="-2.54" y="0" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="8" x="5.08" y="0" visible="pad" length="short" direction="pas" function="dot" rot="R180"/>
<pin name="9" x="-2.54" y="-2.54" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="10" x="5.08" y="-2.54" visible="pad" length="short" direction="pas" function="dot" rot="R180"/>
<pin name="11" x="-2.54" y="-5.08" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="12" x="5.08" y="-5.08" visible="pad" length="short" direction="pas" function="dot" rot="R180"/>
<pin name="13" x="-2.54" y="-7.62" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="14" x="5.08" y="-7.62" visible="pad" length="short" direction="pas" function="dot" rot="R180"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="PINHD-2X7" prefix="JP" uservalue="yes">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<gates>
<gate name="A" symbol="PINH2X7" x="0" y="0"/>
</gates>
<devices>
<device name="" package="2X07">
<connects>
<connect gate="A" pin="1" pad="1"/>
<connect gate="A" pin="10" pad="10"/>
<connect gate="A" pin="11" pad="11"/>
<connect gate="A" pin="12" pad="12"/>
<connect gate="A" pin="13" pad="13"/>
<connect gate="A" pin="14" pad="14"/>
<connect gate="A" pin="2" pad="2"/>
<connect gate="A" pin="3" pad="3"/>
<connect gate="A" pin="4" pad="4"/>
<connect gate="A" pin="5" pad="5"/>
<connect gate="A" pin="6" pad="6"/>
<connect gate="A" pin="7" pad="7"/>
<connect gate="A" pin="8" pad="8"/>
<connect gate="A" pin="9" pad="9"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="/90" package="2X07/90">
<connects>
<connect gate="A" pin="1" pad="1"/>
<connect gate="A" pin="10" pad="10"/>
<connect gate="A" pin="11" pad="11"/>
<connect gate="A" pin="12" pad="12"/>
<connect gate="A" pin="13" pad="13"/>
<connect gate="A" pin="14" pad="14"/>
<connect gate="A" pin="2" pad="2"/>
<connect gate="A" pin="3" pad="3"/>
<connect gate="A" pin="4" pad="4"/>
<connect gate="A" pin="5" pad="5"/>
<connect gate="A" pin="6" pad="6"/>
<connect gate="A" pin="7" pad="7"/>
<connect gate="A" pin="8" pad="8"/>
<connect gate="A" pin="9" pad="9"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="cp150">
<packages>
<package name="CP150_1X4">
<pad name="1" x="-2.2" y="0" drill="0.6"/>
<pad name="2" x="-0.7" y="0" drill="0.6"/>
<pad name="3" x="0.8" y="0" drill="0.6"/>
<pad name="4" x="2.3" y="0" drill="0.6"/>
<wire x1="-3.9" y1="-2.6" x2="4.1" y2="-2.6" width="0.127" layer="21"/>
<wire x1="4.1" y1="-2.6" x2="4.1" y2="1.4" width="0.127" layer="21"/>
<wire x1="4.1" y1="1.4" x2="-3.9" y2="1.4" width="0.127" layer="21"/>
<wire x1="-3.9" y1="1.4" x2="-3.9" y2="-2.6" width="0.127" layer="21"/>
<text x="-4" y="2.4" size="1.27" layer="25">&gt;name</text>
</package>
</packages>
<symbols>
<symbol name="CP150_1X4">
<pin name="1" x="-7.62" y="5.08" length="middle"/>
<pin name="2" x="-7.62" y="2.54" length="middle"/>
<pin name="3" x="-7.62" y="0" length="middle"/>
<pin name="4" x="-7.62" y="-2.54" length="middle"/>
<wire x1="-2.54" y1="7.62" x2="2.54" y2="7.62" width="0.254" layer="94"/>
<wire x1="2.54" y1="7.62" x2="2.54" y2="-5.08" width="0.254" layer="94"/>
<wire x1="2.54" y1="-5.08" x2="-2.54" y2="-5.08" width="0.254" layer="94"/>
<wire x1="-2.54" y1="-5.08" x2="-2.54" y2="7.62" width="0.254" layer="94"/>
<text x="-2.54" y="10.16" size="1.27" layer="95">&gt;name</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="CP150_1X4">
<gates>
<gate name="G$1" symbol="CP150_1X4" x="0" y="-2.54"/>
</gates>
<devices>
<device name="" package="CP150_1X4">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
<connect gate="G$1" pin="3" pad="3"/>
<connect gate="G$1" pin="4" pad="4"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="S1" library="cp150" deviceset="CP150_1X4" device=""/>
<part name="S2" library="cp150" deviceset="CP150_1X4" device=""/>
<part name="S3" library="cp150" deviceset="CP150_1X4" device=""/>
<part name="S4" library="cp150" deviceset="CP150_1X4" device=""/>
<part name="S5" library="cp150" deviceset="CP150_1X4" device=""/>
<part name="S10" library="cp150" deviceset="CP150_1X4" device=""/>
<part name="S9" library="cp150" deviceset="CP150_1X4" device=""/>
<part name="S8" library="cp150" deviceset="CP150_1X4" device=""/>
<part name="S7" library="cp150" deviceset="CP150_1X4" device=""/>
<part name="S6" library="cp150" deviceset="CP150_1X4" device=""/>
<part name="JP2" library="pinhead" deviceset="PINHD-2X7" device=""/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="S1" gate="G$1" x="-20.32" y="45.72" rot="R180"/>
<instance part="S2" gate="G$1" x="-20.32" y="27.94" rot="R180"/>
<instance part="S3" gate="G$1" x="-20.32" y="10.16" rot="R180"/>
<instance part="S4" gate="G$1" x="-20.32" y="-7.62" rot="R180"/>
<instance part="S5" gate="G$1" x="-20.32" y="-25.4" rot="R180"/>
<instance part="S10" gate="G$1" x="10.16" y="-25.4" rot="R180"/>
<instance part="S9" gate="G$1" x="10.16" y="-7.62" rot="R180"/>
<instance part="S8" gate="G$1" x="10.16" y="10.16" rot="R180"/>
<instance part="S7" gate="G$1" x="10.16" y="27.94" rot="R180"/>
<instance part="S6" gate="G$1" x="10.16" y="45.72" rot="R180"/>
<instance part="JP2" gate="A" x="66.04" y="7.62"/>
</instances>
<busses>
</busses>
<nets>
<net name="DIG3" class="0">
<segment>
<wire x1="17.78" y1="-5.08" x2="20.32" y2="-5.08" width="0.1524" layer="91"/>
<label x="22.86" y="-5.08" size="1.778" layer="95"/>
<pinref part="S9" gate="G$1" pin="4"/>
</segment>
<segment>
<pinref part="JP2" gate="A" pin="12"/>
<wire x1="71.12" y1="2.54" x2="76.2" y2="2.54" width="0.1524" layer="91"/>
<label x="78.74" y="2.54" size="1.778" layer="95"/>
</segment>
</net>
<net name="MOVE" class="0">
<segment>
<wire x1="-12.7" y1="45.72" x2="-10.16" y2="45.72" width="0.1524" layer="91"/>
<label x="-7.62" y="45.72" size="1.778" layer="95"/>
<pinref part="S1" gate="G$1" pin="3"/>
</segment>
<segment>
<wire x1="-12.7" y1="27.94" x2="-10.16" y2="27.94" width="0.1524" layer="91"/>
<label x="-7.62" y="27.94" size="1.778" layer="95"/>
<pinref part="S2" gate="G$1" pin="3"/>
</segment>
<segment>
<wire x1="-12.7" y1="10.16" x2="-10.16" y2="10.16" width="0.1524" layer="91"/>
<label x="-7.62" y="10.16" size="1.778" layer="95"/>
<pinref part="S3" gate="G$1" pin="3"/>
</segment>
<segment>
<wire x1="-12.7" y1="-7.62" x2="-10.16" y2="-7.62" width="0.1524" layer="91"/>
<label x="-7.62" y="-7.62" size="1.778" layer="95"/>
<pinref part="S4" gate="G$1" pin="3"/>
</segment>
<segment>
<wire x1="-12.7" y1="-25.4" x2="-10.16" y2="-25.4" width="0.1524" layer="91"/>
<label x="-7.62" y="-25.4" size="1.778" layer="95"/>
<pinref part="S5" gate="G$1" pin="3"/>
</segment>
<segment>
<wire x1="17.78" y1="45.72" x2="20.32" y2="45.72" width="0.1524" layer="91"/>
<label x="22.86" y="45.72" size="1.778" layer="95"/>
<pinref part="S6" gate="G$1" pin="3"/>
</segment>
<segment>
<wire x1="17.78" y1="27.94" x2="20.32" y2="27.94" width="0.1524" layer="91"/>
<label x="22.86" y="27.94" size="1.778" layer="95"/>
<pinref part="S7" gate="G$1" pin="3"/>
</segment>
<segment>
<wire x1="17.78" y1="10.16" x2="20.32" y2="10.16" width="0.1524" layer="91"/>
<label x="22.86" y="10.16" size="1.778" layer="95"/>
<pinref part="S8" gate="G$1" pin="3"/>
</segment>
<segment>
<wire x1="17.78" y1="-7.62" x2="20.32" y2="-7.62" width="0.1524" layer="91"/>
<label x="22.86" y="-7.62" size="1.778" layer="95"/>
<pinref part="S9" gate="G$1" pin="3"/>
</segment>
<segment>
<wire x1="17.78" y1="-25.4" x2="20.32" y2="-25.4" width="0.1524" layer="91"/>
<label x="22.86" y="-25.4" size="1.778" layer="95"/>
<pinref part="S10" gate="G$1" pin="3"/>
</segment>
<segment>
<pinref part="JP2" gate="A" pin="11"/>
<wire x1="63.5" y1="2.54" x2="58.42" y2="2.54" width="0.1524" layer="91"/>
<label x="50.8" y="2.54" size="1.778" layer="95"/>
</segment>
</net>
<net name="5V" class="0">
<segment>
<wire x1="-12.7" y1="43.18" x2="-10.16" y2="43.18" width="0.1524" layer="91"/>
<label x="-7.62" y="43.18" size="1.778" layer="95"/>
<pinref part="S1" gate="G$1" pin="2"/>
</segment>
<segment>
<wire x1="-12.7" y1="25.4" x2="-10.16" y2="25.4" width="0.1524" layer="91"/>
<label x="-7.62" y="25.4" size="1.778" layer="95"/>
<pinref part="S2" gate="G$1" pin="2"/>
</segment>
<segment>
<wire x1="-12.7" y1="7.62" x2="-10.16" y2="7.62" width="0.1524" layer="91"/>
<label x="-7.62" y="7.62" size="1.778" layer="95"/>
<pinref part="S3" gate="G$1" pin="2"/>
</segment>
<segment>
<wire x1="-12.7" y1="-10.16" x2="-10.16" y2="-10.16" width="0.1524" layer="91"/>
<label x="-7.62" y="-10.16" size="1.778" layer="95"/>
<pinref part="S4" gate="G$1" pin="2"/>
</segment>
<segment>
<wire x1="-12.7" y1="-27.94" x2="-10.16" y2="-27.94" width="0.1524" layer="91"/>
<label x="-7.62" y="-27.94" size="1.778" layer="95"/>
<pinref part="S5" gate="G$1" pin="2"/>
</segment>
<segment>
<wire x1="17.78" y1="43.18" x2="20.32" y2="43.18" width="0.1524" layer="91"/>
<label x="22.86" y="43.18" size="1.778" layer="95"/>
<pinref part="S6" gate="G$1" pin="2"/>
</segment>
<segment>
<wire x1="17.78" y1="25.4" x2="20.32" y2="25.4" width="0.1524" layer="91"/>
<label x="22.86" y="25.4" size="1.778" layer="95"/>
<pinref part="S7" gate="G$1" pin="2"/>
</segment>
<segment>
<wire x1="17.78" y1="7.62" x2="20.32" y2="7.62" width="0.1524" layer="91"/>
<label x="22.86" y="7.62" size="1.778" layer="95"/>
<pinref part="S8" gate="G$1" pin="2"/>
</segment>
<segment>
<wire x1="17.78" y1="-10.16" x2="20.32" y2="-10.16" width="0.1524" layer="91"/>
<label x="22.86" y="-10.16" size="1.778" layer="95"/>
<pinref part="S9" gate="G$1" pin="2"/>
</segment>
<segment>
<wire x1="17.78" y1="-27.94" x2="20.32" y2="-27.94" width="0.1524" layer="91"/>
<label x="22.86" y="-27.94" size="1.778" layer="95"/>
<pinref part="S10" gate="G$1" pin="2"/>
</segment>
<segment>
<pinref part="JP2" gate="A" pin="7"/>
<wire x1="63.5" y1="7.62" x2="58.42" y2="7.62" width="0.1524" layer="91"/>
<label x="50.8" y="7.62" size="1.778" layer="95"/>
</segment>
</net>
<net name="GND" class="0">
<segment>
<wire x1="-12.7" y1="40.64" x2="-10.16" y2="40.64" width="0.1524" layer="91"/>
<label x="-7.62" y="40.64" size="1.778" layer="95"/>
<pinref part="S1" gate="G$1" pin="1"/>
</segment>
<segment>
<wire x1="-12.7" y1="22.86" x2="-10.16" y2="22.86" width="0.1524" layer="91"/>
<label x="-7.62" y="22.86" size="1.778" layer="95"/>
<pinref part="S2" gate="G$1" pin="1"/>
</segment>
<segment>
<wire x1="-12.7" y1="5.08" x2="-10.16" y2="5.08" width="0.1524" layer="91"/>
<label x="-7.62" y="5.08" size="1.778" layer="95"/>
<pinref part="S3" gate="G$1" pin="1"/>
</segment>
<segment>
<wire x1="-12.7" y1="-12.7" x2="-10.16" y2="-12.7" width="0.1524" layer="91"/>
<label x="-7.62" y="-12.7" size="1.778" layer="95"/>
<pinref part="S4" gate="G$1" pin="1"/>
</segment>
<segment>
<wire x1="-12.7" y1="-30.48" x2="-10.16" y2="-30.48" width="0.1524" layer="91"/>
<label x="-7.62" y="-30.48" size="1.778" layer="95"/>
<pinref part="S5" gate="G$1" pin="1"/>
</segment>
<segment>
<wire x1="17.78" y1="40.64" x2="20.32" y2="40.64" width="0.1524" layer="91"/>
<label x="22.86" y="40.64" size="1.778" layer="95"/>
<pinref part="S6" gate="G$1" pin="1"/>
</segment>
<segment>
<wire x1="17.78" y1="22.86" x2="20.32" y2="22.86" width="0.1524" layer="91"/>
<label x="22.86" y="22.86" size="1.778" layer="95"/>
<pinref part="S7" gate="G$1" pin="1"/>
</segment>
<segment>
<wire x1="17.78" y1="5.08" x2="20.32" y2="5.08" width="0.1524" layer="91"/>
<label x="22.86" y="5.08" size="1.778" layer="95"/>
<pinref part="S8" gate="G$1" pin="1"/>
</segment>
<segment>
<wire x1="17.78" y1="-12.7" x2="20.32" y2="-12.7" width="0.1524" layer="91"/>
<label x="22.86" y="-12.7" size="1.778" layer="95"/>
<pinref part="S9" gate="G$1" pin="1"/>
</segment>
<segment>
<wire x1="17.78" y1="-30.48" x2="20.32" y2="-30.48" width="0.1524" layer="91"/>
<label x="22.86" y="-30.48" size="1.778" layer="95"/>
<pinref part="S10" gate="G$1" pin="1"/>
</segment>
<segment>
<pinref part="JP2" gate="A" pin="9"/>
<wire x1="63.5" y1="5.08" x2="58.42" y2="5.08" width="0.1524" layer="91"/>
<label x="50.8" y="5.08" size="1.778" layer="95"/>
</segment>
</net>
<net name="DIG1" class="0">
<segment>
<wire x1="17.78" y1="30.48" x2="20.32" y2="30.48" width="0.1524" layer="91"/>
<label x="22.86" y="30.48" size="1.778" layer="95"/>
<pinref part="S7" gate="G$1" pin="4"/>
</segment>
<segment>
<pinref part="JP2" gate="A" pin="13"/>
<wire x1="63.5" y1="0" x2="58.42" y2="0" width="0.1524" layer="91"/>
<label x="50.8" y="0" size="1.778" layer="95"/>
</segment>
</net>
<net name="DIG2" class="0">
<segment>
<wire x1="17.78" y1="12.7" x2="20.32" y2="12.7" width="0.1524" layer="91"/>
<label x="22.86" y="12.7" size="1.778" layer="95"/>
<pinref part="S8" gate="G$1" pin="4"/>
</segment>
<segment>
<pinref part="JP2" gate="A" pin="14"/>
<wire x1="71.12" y1="0" x2="76.2" y2="0" width="0.1524" layer="91"/>
<label x="78.74" y="0" size="1.778" layer="95"/>
</segment>
</net>
<net name="DIG4" class="0">
<segment>
<wire x1="17.78" y1="-22.86" x2="20.32" y2="-22.86" width="0.1524" layer="91"/>
<label x="22.86" y="-22.86" size="1.778" layer="95"/>
<pinref part="S10" gate="G$1" pin="4"/>
</segment>
<segment>
<pinref part="JP2" gate="A" pin="10"/>
<wire x1="71.12" y1="5.08" x2="76.2" y2="5.08" width="0.1524" layer="91"/>
<label x="78.74" y="5.08" size="1.778" layer="95"/>
</segment>
</net>
<net name="PWM1" class="0">
<segment>
<wire x1="-12.7" y1="48.26" x2="-10.16" y2="48.26" width="0.1524" layer="91"/>
<label x="-7.62" y="48.26" size="1.778" layer="95"/>
<pinref part="S1" gate="G$1" pin="4"/>
</segment>
<segment>
<pinref part="JP2" gate="A" pin="8"/>
<wire x1="71.12" y1="7.62" x2="76.2" y2="7.62" width="0.1524" layer="91"/>
<label x="78.74" y="7.62" size="1.778" layer="95"/>
</segment>
</net>
<net name="PWM2" class="0">
<segment>
<wire x1="-12.7" y1="30.48" x2="-10.16" y2="30.48" width="0.1524" layer="91"/>
<label x="-7.62" y="30.48" size="1.778" layer="95"/>
<pinref part="S2" gate="G$1" pin="4"/>
</segment>
<segment>
<pinref part="JP2" gate="A" pin="6"/>
<wire x1="71.12" y1="10.16" x2="76.2" y2="10.16" width="0.1524" layer="91"/>
<label x="78.74" y="10.16" size="1.778" layer="95"/>
</segment>
</net>
<net name="PWM3" class="0">
<segment>
<wire x1="-12.7" y1="12.7" x2="-10.16" y2="12.7" width="0.1524" layer="91"/>
<label x="-7.62" y="12.7" size="1.778" layer="95"/>
<pinref part="S3" gate="G$1" pin="4"/>
</segment>
<segment>
<pinref part="JP2" gate="A" pin="4"/>
<wire x1="71.12" y1="12.7" x2="76.2" y2="12.7" width="0.1524" layer="91"/>
<label x="78.74" y="12.7" size="1.778" layer="95"/>
</segment>
</net>
<net name="PWM4" class="0">
<segment>
<wire x1="-12.7" y1="-5.08" x2="-10.16" y2="-5.08" width="0.1524" layer="91"/>
<label x="-7.62" y="-5.08" size="1.778" layer="95"/>
<pinref part="S4" gate="G$1" pin="4"/>
</segment>
<segment>
<pinref part="JP2" gate="A" pin="2"/>
<wire x1="71.12" y1="15.24" x2="76.2" y2="15.24" width="0.1524" layer="91"/>
<label x="78.74" y="15.24" size="1.778" layer="95"/>
</segment>
</net>
<net name="PWM5" class="0">
<segment>
<wire x1="-12.7" y1="-22.86" x2="-10.16" y2="-22.86" width="0.1524" layer="91"/>
<label x="-7.62" y="-22.86" size="1.778" layer="95"/>
<pinref part="S5" gate="G$1" pin="4"/>
</segment>
<segment>
<pinref part="JP2" gate="A" pin="1"/>
<wire x1="63.5" y1="15.24" x2="58.42" y2="15.24" width="0.1524" layer="91"/>
<label x="50.8" y="15.24" size="1.778" layer="95"/>
</segment>
</net>
<net name="PWM6" class="0">
<segment>
<wire x1="17.78" y1="48.26" x2="20.32" y2="48.26" width="0.1524" layer="91"/>
<label x="22.86" y="48.26" size="1.778" layer="95"/>
<pinref part="S6" gate="G$1" pin="4"/>
</segment>
<segment>
<pinref part="JP2" gate="A" pin="3"/>
<wire x1="63.5" y1="12.7" x2="58.42" y2="12.7" width="0.1524" layer="91"/>
<label x="50.8" y="12.7" size="1.778" layer="95"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
</eagle>
